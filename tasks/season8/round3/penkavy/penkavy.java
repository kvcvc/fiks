import org.apache.commons.text.similarity.LevenshteinDistance;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.*;

public class penkavy {
    public static void main(String[] args) {
        try {
            System.setOut(new PrintStream(new FileOutputStream("output.txt")));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        for (int i = 0; i < T; i++) {
            int N = sc.nextInt(), K = sc.nextInt();
            LevenshteinDistance lev = new LevenshteinDistance(K);
            int[] indexes = new int[N];
            HashMap<Integer, String> DNAs = new HashMap<Integer, String>();
            for ( int j = 0; j < N; j++) {
                indexes[j] = j;
                int L = sc.nextInt();
                sc.skip(" ");
                String DNA = sc.nextLine();
                DNAs.put(j, DNA);
            }
            
            ArrayList<int[]> combinations = new ArrayList<>();
            for (int j = 0; j < (indexes.length - 2); j++) {
                for (int k = (j + 1); k < (indexes.length - 1); k++) {
                    for (int m = (k + 1); m < indexes.length; m++) {
                        combinations.add(new int[]{indexes[j], indexes[k], indexes[m]});
                    }
                }
            }

            ArrayList<int[]> interesting = new ArrayList<>();
            for (int j = 0; j < combinations.size(); j++) {
                int A = combinations.get(j)[0], B = combinations.get(j)[1], C = combinations.get(j)[2];
                if (lev.apply(DNAs.get(B), DNAs.get(A)) != -1 && lev.apply(DNAs.get(B), DNAs.get(C)) != -1 && lev.apply(DNAs.get(A), DNAs.get(C)) == -1) {
                    interesting.add(new int[]{A, B, C});
                } else if (lev.apply(DNAs.get(C), DNAs.get(A)) != -1 && lev.apply(DNAs.get(C), DNAs.get(B)) != -1 && lev.apply(DNAs.get(A), DNAs.get(B)) == -1) {
                    interesting.add(new int[]{A, C, B});
                } else if (lev.apply(DNAs.get(A), DNAs.get(B)) != -1 && lev.apply(DNAs.get(A), DNAs.get(C)) != -1 && lev.apply(DNAs.get(B), DNAs.get(C)) == -1) {
                    interesting.add(new int[]{B, A, C});
                } else if (lev.apply(DNAs.get(C), DNAs.get(B)) != -1 && lev.apply(DNAs.get(C), DNAs.get(A)) != -1 && lev.apply(DNAs.get(B), DNAs.get(A)) == -1) {
                    interesting.add(new int[]{B, C, A});
                } else if (lev.apply(DNAs.get(B), DNAs.get(C)) != -1 && lev.apply(DNAs.get(B), DNAs.get(A)) != -1 && lev.apply(DNAs.get(C), DNAs.get(A)) == -1) {
                    interesting.add(new int[]{C, B, A});
                } else if (lev.apply(DNAs.get(A), DNAs.get(C)) != -1 && lev.apply(DNAs.get(A), DNAs.get(B)) != -1 && lev.apply(DNAs.get(C), DNAs.get(B)) == -1) {
                    interesting.add(new int[]{C, A, B});
                }
            }

            interesting.sort(Comparator.comparingInt(a -> a[0]));
            System.out.println(interesting.size());
            for (int j = 0; j < interesting.size(); j++) {
                System.out.printf("%d %d %d\n", interesting.get(j)[0], interesting.get(j)[1], interesting.get(j)[2]);
            }
        }
    }
}
