```
        int oldR = nums.length;
        int oldC = nums[0].length;
        if(oldR*oldC!=r*c){
            return nums;
        }
        int row = 0;
        int col = 0;
        int[][] res = new int[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if(col>=oldC){
                    row++;
                    col = 0;
                }
                res[i][j] = nums[row][col];
                col++;

            }
        }

        return res;```