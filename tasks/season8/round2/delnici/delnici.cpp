#include <iostream>
#include <string>
#include <map>
#include <list>
#include <utility>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
	cin >> t;
    for (int i = 0; i < t; i++) {
        int n, p;
	    cin >> n;
        list<pair<int, int>> *adj = new list<pair<int, int>>[n];
        map<string, int> jazyky;
        for (int j = 0; j < n; j++) {
            string jazyk;
            cin >> jazyk;
            jazyky.insert({jazyk, j});
        }
        cin >> p;
        for (int j = 0; j < p; j++) {
            int m, c;
            cin >> m >> c;
            vector<string> prekladany;
            for (int k = 0; k < m; k++) {
                string jazyk;
                cin >> jazyk;
                prekladany.push_back(jazyk);
            }
            for (int k = 0; k < prekladany.size(); k++) {
                for (int l = 0; l < prekladany.size(); l++) {
                    if (prekladany[l] != prekladany[k]) {
                        adj[jazyky.at(prekladany[l])].push_back(make_pair(jazyky.at(prekladany[k]), c));
                    }
                }
            }
        }
        string x, y;
        cin >> x >> y;
        int s = jazyky.at(x);
        int d = jazyky.at(y);

        set<pair<int, int>> extract_set;
        vector<int> distances(n, INT_MAX);
        extract_set.insert(make_pair(0, s));
        distances[s] = 0;
        int parent[n];

        while(!extract_set.empty()){
            pair<int, int> tmp = *(extract_set.begin());
            extract_set.erase(extract_set.begin());
            int u = tmp.second;
            
            for(auto i = adj[u].begin(); i != adj[u].end(); i++) {
                int v = (*i).first;
                int weight = (*i).second;

                if(distances[v] > distances[u] + weight) {
                    if (distances[v] != INT_MAX) {
                        extract_set.erase(extract_set.find(make_pair(distances[v], v)));
                    }

                    distances[v] = distances[u] + weight;
                    parent[v] = u;
                    extract_set.insert(make_pair(distances[v], v));
                }
            }
        }

        if (distances[d] == INT_MAX) {
            cout << "Takove prekladatele nemame.\n";
        } else {
            cout << "To nas bude stat " << distances[d] << ",-." << endl;
            
            if (d == 0) {
                cout << "Pocet prekladu: 1." << endl;
                for (auto it = jazyky.begin(); it != jazyky.end(); ++it) {
                    if (it->second == s) {
                        cout << it->first << endl;
                    }
                    
                }
                for (auto it = jazyky.begin(); it != jazyky.end(); ++it) {
                    if (it->second == d) {
                        cout << it->first << endl;
                    }
                    
                }
                return 0;
            }
            
            vector<int> queue;
            vector<int> print;
            queue.push_back(parent[d]);
            while (queue.size() != 0) {
                if (queue.back() != s) {
                    queue.push_back(parent[queue.back()]);
                }

                print.push_back(queue.front());
                queue.erase(queue.begin());
            }
            reverse(print.begin(), print.end());
            print.push_back(d);
            cout << "Pocet prekladu: " << print.size() - 1 << "." << endl;
            for (int j = 0; j < print.size(); j++) {
                for (auto it = jazyky.begin(); it != jazyky.end(); ++it) {
                    if (it->second == print[j]) {
                        cout << it->first << "\n";
                    }
                }
            }
        }
    }
}
