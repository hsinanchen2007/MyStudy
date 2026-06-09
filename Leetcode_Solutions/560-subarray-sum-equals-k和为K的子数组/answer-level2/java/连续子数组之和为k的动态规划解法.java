### 解题思路
假设sum(i,j)表示为第i+1个元素到第j个元素之和,那么sum(i,j)=sum(0,j)-sum(0,i)
所以假定我们得到了一个dp[x] 动态规划数组 x表示nums数组的下标,假设数组的每一项表示第i个索引到第0个索引的综合。
那么我们计算两种情况:
1、dp[x]本身=k,说明(0,x)就是满足这样条件的子序列
2、dp[j]-dp[i]=k,说明(i+1,j)也是满足这样条件的子序列

### 代码

```java
class Solution {
    public int subarraySum(int[] nums, int k) {
        int length = nums.length;
        int dp[]= new int[length];
        for(int i=0;i<nums.length;i++){
            dp[i] = (i==0)?nums[i]:dp[i-1]+nums[i];
        }
        int count = 0;
        for(int dpLength:dp){
            if(dpLength==k){
                count+=1;
            }
        }
        int startIndex = 0;
        for(int i = startIndex;i<length;i++){
            for(int j=i+1;j<length;j++){
                if(dp[j]-dp[i]==k){
                    count+=1;
                }
            }
        }
        return count;
    }
}
```