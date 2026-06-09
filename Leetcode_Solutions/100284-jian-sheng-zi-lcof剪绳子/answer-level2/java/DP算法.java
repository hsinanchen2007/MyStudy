### 解题思路
执行用时 : 1 ms , 在所有 Java 提交中击败了 44.02% 的用户 
内存消耗 : 36.4 MB , 在所有 Java 提交中击败了 100.00% 的用户

别人看到 8是2*3*3 10是4*3*3 能猜出来3作为基数，我特么怎么就想着大部分数字尽量一样呢？？

### 代码

```java

class Solution {
    public int cuttingRope(int n) {
        // 二维数组动态规划，，，太慢了。。
        // int result = 1;
        // int[][] results = new int[n+1][n+1];
        // for(int i =0;i<=n;i++){
        //     for(int j=0;j<=n;j++){
        //         if(j==0){
        //             results[i][j]=0;
        //             continue;
        //         }
        //         if(j==1){
        //             results[i][j] = i;
        //             continue;
        //         }
        //         int max = 0;
        //         //长度为i的绳子，分为j段的最大值
        //         for(int l=1;l<i;l++){
        //             int length = l*(results[i-l][j-1]);
        //             if(length>max){
        //                 max = length;
        //             }
        //         }
        //         results[i][j] = max;
        //         if(max>result){
        //             result = max;
        //         }
        //     }
        // }
        // return result;
        
        // 一维数组动态规划 
        if(n==2){
            return 1;
        }
        if(n==3){
            return 2;
        }
        int[] results = new int[n+1];
        results[1] = 1;
        results[2] = 1;
        results[3] = 2;
        for(int i =4;i<=n;i++){
            int max = 1;
            // 假设一段绳子的长度是j
            for(int j=1;j<i;j++){
                // 注意是 j*results[i-j]和j*(i-j)的较大者，因为另一段可以不分
                int result = Math.max(j*results[i-j],j*(i-j));
                if(result>max){
                    max = result;
                }
            }
            results[i] = max;
        }
        return results[n];
    }
    
}
```