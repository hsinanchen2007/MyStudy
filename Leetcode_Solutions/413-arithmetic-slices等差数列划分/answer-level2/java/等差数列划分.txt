### 解题思路
1.了解每增加一个元素，等差子数组增加几个，找到依赖关系，不要重复计算，
2.dp[i]代表增加一个I之后，其增加的子数组个数。动态规划就是找可变参数之间的依赖关系。  

### 代码

```java
class Solution {
    public int numberOfArithmeticSlices(int[] A) {
        if(A.length==0) return 0;
        int n=A.length;
        int[] dp=new int[n];
        for(int i=2;i<n;i++){
            if(A[i]-A[i-1]==A[i-1]-A[i-2]){
                dp[i]=1+dp[i-1];
            }
        }
        int total=0;
        for(int ele:dp){
            total+=ele;
        }
        return total;
    }
}
```