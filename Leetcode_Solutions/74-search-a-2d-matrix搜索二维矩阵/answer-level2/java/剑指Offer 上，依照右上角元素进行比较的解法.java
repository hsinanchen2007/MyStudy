 public boolean searchMatrix(int[][] matrix, int target) {
           int row = matrix.length;
           if (row == 0){return false;}
           int col = matrix[0].length;
           if (col == 0){return false;}
           int rowNum=0,colNum=col-1;
           while (rowNum<row&&target>=matrix[rowNum][colNum]){
               if (target == matrix[rowNum][colNum]){ return true; }
               rowNum++;
           }
           if (rowNum==row){return false;}
           while (colNum>-1&&target<=matrix[rowNum][colNum]){
               if (target == matrix[rowNum][colNum]){return true;}
               colNum--;
           }
           if(colNum == -1){return  false;}
           
           return false;
    }