### 解题思路
 总问题求解思路：通过计算每一个子问题（A（0，i）的最大和）来找到最终输入数组的最大和，但是问题出在第i个子问题的最大值怎么求
 A（0，i）求解思路：从i点往前最多搜索k个点，每个点设为j，则会出现多种情况，每种情况用已经求得的最大子问题来计算，得到
 得到当前子问题求解结果

### 代码

```java
class Solution {
    
    public int maxSumAfterPartitioning(int[] A, int K) {
        int[] maxSum=new int[A.length];
        maxSum[0]=A[0];
        for(int i=1;i<A.length;i++){
            int maxA=A[i];
            for(int j=0;j<K&&j<=i;j++){
                maxA=Math.max(maxA,A[i-j]);
                if((i-j)>0){
                    maxSum[i]=Math.max(maxSum[i],(maxSum[i-j-1]+maxA*(j+1)));
                } else{
                    maxSum[i]=Math.max(maxSum[i],(maxA*(j+1)));
                }
                
            }
        }
        return maxSum[A.length-1];
    }
}
```