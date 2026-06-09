### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[][] generateMatrix(int n) {
        int end = n*n;
        int[][] res = new int[n][n];
        int left = 0,right = n-1;
        int top = 0,bottom =n-1;
        int num = 1;
        while(left <= right && top <= bottom){
            for(int i=left;i<=right;i++){
                res[top][i] = num;
                num++;
            }

            for(int j=top+1;j<=bottom;j++){
                res[j][right] = num;
                num++; 
            }
            if(top !=bottom){
               for(int i=right-1;i>=left;i--){
                    res[bottom][i] = num;
                    num++;
                }
            }
            if(left != right){
                for(int i=bottom-1;i>top;i--){
                    res[i][left]= num;
                    num++;
                }
            }
            
            top++;
            left++;
            right--;
            bottom--;

        }
        return res;
    }
}
```