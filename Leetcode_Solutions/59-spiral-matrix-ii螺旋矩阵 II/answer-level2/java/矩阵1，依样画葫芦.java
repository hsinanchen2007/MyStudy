public int[][] generateMatrix(int n) {
        if(n  == 0){
            return null;
        }
        if(n == 1){
            int[][]result = {{n}};
            return result;
        }
        int size = n * n;
        int xMin = 0,xMax = n - 1,yMin = 0,yMax = n - 1;
        int[][]result = new int[n][n];
        int k = 1;
        while(k <= size){
            for(int y = yMin;y <= yMax;y++){
                result[xMin][y] = k;
                k++;
            }
            if(k > size){
                break;
            }
            xMin++;
            for(int x = xMin;x <= xMax;x++){
                result[x][yMax] = k;
                k++;
            }
            if(k > size){
                break;
            }
            yMax--;
            for(int y = yMax;y >= yMin;y--){
                result[xMax][y] = k;
                k++;
            }
            if(k > size){
                break;
            }
            xMax--;
            for(int x = xMax;x >= xMin;x--){
                result[x][yMin] = k;
                k++;
            }
            if(k > size){
                break;
            }
            yMin++;
        }
        return result;
    }