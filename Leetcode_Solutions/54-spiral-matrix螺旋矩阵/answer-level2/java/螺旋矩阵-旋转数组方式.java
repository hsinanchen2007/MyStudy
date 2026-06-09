static class Solution {
        public List<Integer> spiralOrder(int[][] matrix) {
            List<Integer> list = new ArrayList<>();
            if(matrix == null || matrix.length == 0 || matrix[0].length == 0)
                return list;
            while(matrix.length > 0){
                for(int i = 0; i < matrix[0].length; i++)
                    list.add(matrix[0][i]);
                if(matrix.length == 1)
                    break;
                matrix = xuanzhuan(matrix);
            }
            return list;
        }
        public int[][] xuanzhuan(int matrix[][]){
            int rows = matrix.length;
            int cols = matrix[0].length;
            int newMatrix[][] = new int[cols][rows - 1];
            for(int i = 1; i < rows; i++){
                for(int j = 0; j < cols; j++){
                    newMatrix[cols - j - 1][i-1] = matrix[i][j];
                    System.out.println(matrix[i][j]);
                }
            }
            return newMatrix;
        }
    }