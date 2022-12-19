```
class Solution {
    //执行用时 :1 ms, 在所有 Java 提交中击败了91.31%的用户
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ans = new ArrayList<>();
        if(matrix == null || matrix.length == 0 || matrix[0].length == 0){
            return ans;
        }
        
        int up = 0;
        int left = 0;
        int down = matrix.length - 1;
        int right = matrix[0].length - 1;
        
        
        while(true){
            for(int i = left; i <= right; i++){
                ans.add(matrix[up][i]);
            }
            if(++up > down){
                break;
            }
            
            for(int i = up; i <= down; i++){
                ans.add(matrix[i][right]);
            }
            if(--right < left){
                break;
            }
            
            for(int i = right; i >= left; i--){
                ans.add(matrix[down][i]);
            }
            if(--down < up){
                break;
            }
            for(int i = down; i >= up; i--){
                ans.add(matrix[i][left]);
            }
            if(++left > right){
                break;
            }
            
            
        }
        
        return ans;
        
        
        
    }
    
}
```
