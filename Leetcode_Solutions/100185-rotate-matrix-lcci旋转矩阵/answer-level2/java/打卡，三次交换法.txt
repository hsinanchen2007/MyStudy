    
    class Solution {
        public void rotate(int[][] matrix) {
            int p = 0;
            int q = matrix.length - 1;
            while(p < q) {
                for(int i = p;i < q;i++) {
                    swap(matrix, p, i, i, q);
                    swap(matrix, p, i, q, q - (i - p));
                    swap(matrix, p, i, q - (i - p), p);
                }
                p++;
                q--;
            }
        }

        public void swap(int[][] matrix, int i, int j, int k, int z) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[k][z];
            matrix[k][z] = temp;
        }
    }