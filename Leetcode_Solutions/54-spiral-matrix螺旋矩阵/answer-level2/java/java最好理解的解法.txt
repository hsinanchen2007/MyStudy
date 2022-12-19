主要是上界和下届的判断
然后在判断是不是结束了
```
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> res = new ArrayList<Integer>();
        int M = matrix.length;
        if(M==0) return res;
        int N = matrix[0].length;
        int x_min = 0;
        int x_max = M-1;
        int y_min = 0;
        int y_max = N-1;
        int count = M*N;
        while(x_min<=x_max||y_min<=y_max){
            for(int i = y_min;i<=y_max;i++){
                res.add(matrix[x_min][i]);
            }
            x_min++;
            if(x_min>x_max){
                break;
            }
            for(int i = x_min;i<=x_max;i++){
                res.add(matrix[i][y_max]);
            }
            y_max--;
            if(y_min>y_max){
                break;
            }
            for(int i = y_max;i>=y_min;i--){
                res.add(matrix[x_max][i]);
            }
            x_max--;
            if(x_min>x_max){
                break;
            }
            for(int i = x_max;i>=x_min;i--){
                res.add(matrix[i][y_min]);
            }
            y_min++;
            if(y_min>y_max){
                break;
            }
        }



        return res;
       
    }
}
```
