    
    class Solution {
        public int maximalSquare(char[][] matrix) {
            if(matrix.length == 0) {
                return 0;
            }
            int res = 0;
            int m = matrix.length;
            int n = matrix[0].length;
            for(int i = 0;i < m;i++) {
                for(int j = 0;j < n;j++) {
                    if(matrix[i][j] == '1') {
                        res = Math.max(res, getArea(matrix, i, j));
                    }
                }
            }
            return res;
        }

        public int getArea(char[][] matrix, int x, int y) {
            int m = matrix.length;
            int n = matrix[0].length;
            int res = 1;
            for(int i = x + 1, j = y + 1;i < m && j < n;i++, j++) {
                int p = i, q = j;
                while(p >= x && matrix[p][j] == '1') {p--;}
                while(q >= y && matrix[i][q] == '1') {q--;}
                if(p == x - 1 && q == y - 1) {
                    res = (i - x + 1) * (i - x + 1);
                }else {
                    return res;
                }
            }
            return res;
        }
    }