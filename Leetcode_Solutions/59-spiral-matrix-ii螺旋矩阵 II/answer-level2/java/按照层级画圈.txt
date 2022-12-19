执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户

按照层级循环

```
public int[][] generateMatrix(int n) {
        int[][] res = new int[n][n];
        //按照层级进行填充数据
        int temp = 1;
        //每层开始的数字
        int start = 0;
        while(temp<=n){
            //横
            for(int i=temp ; i<=n-temp+1;i++){
                start++;
                res[temp-1][i-1] = start;
            }
            //竖
            for(int i=temp+1 ; i<=n-temp+1;i++){
                start++;
                res[i-1][n-temp+1-1] = start;
            }
            //回
            for(int i=n-temp+1-1 ; i>=temp;i--){
                start++;
                res[n-temp+1-1][i-1] = start;
            }
            //提
            for(int i=n-temp+1-1 ; i>=temp+1;i--){
                start++;
                res[i-1][temp-1] = start;
            }
            temp+=1;
        }
        return res;
    }
```
