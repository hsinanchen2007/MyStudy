```
public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> list = new ArrayList<>();
        if(matrix.length == 0) return list;
        int left = 0,right = matrix[left].length-1,up = 0, bottom = matrix.length-1;
        while(true){
            for(int i = left;i <= right;i ++){
                list.add(matrix[up][i]);
            }
            if(++up > bottom) break;
            for(int i = up;i <= bottom;i ++){
                list.add(matrix[i][right]);
            }
            if(--right < left) break;
            for(int i = right;i >= left;i --){
                list.add(matrix[bottom][i]);
            }
            if(--bottom < up) break;
            for(int i = bottom;i >= up;i --){
                list.add(matrix[i][left]);
            }
            if(++left > right) break;
        }
        return list;

    }
```