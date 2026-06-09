### 解题思路
对于本题的解题思路是：DFS(超时) -> 动态规划O(n^2)(14ms,37.7MB) -> 贪心算法(3ms,37.5MB) -> 贪心算法+二分查找(1ms,37.8MB)

### 代码
一开始没想出好的方法，就试了一下DFS，等于穷举，当然超时了
```java
class Solution {
    int result = 0;
    public int lengthOfLIS(int[] nums) {
        dfs(nums,0,new ArrayList<>());
        return result;
    }
    public void dfs(int[] nums,int i,List<Integer> l){
        result = Math.max(l.size(),result);
        if(i>=nums.length) return ;
        for(int k=i;k<nums.length;k++){
            if(l.size()!=0 && nums[k]<=l.get(l.size()-1)) continue;
            l.add(nums[k]);
            dfs(nums,k+1,l);
            l.remove(l.size()-1);
        }
    }
}
```
动态规划：定义dp[i]表示前i个值可以组成的最长上升序列的长度，然后求dp[i+1]的时候用k遍历前面i个dp值，取nums[k]<nums[i+1]中dp[k]的最大值再加1，时间复杂度是O(n^2):
```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        if(nums.length<=1) return nums.length;
        int max = 0;
        int[] dp = new int[nums.length];
        dp[0] = 1;
        for(int i=1;i<nums.length;i++){
            dp[i] = 1;
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]){
                    dp[i] = Math.max(dp[i],dp[j]+1);
                }
            }
            max = Math.max(max,dp[i]);
        }
        return max;
    }
}
```
贪心算法：使用一个数组tmp，遍历nums，如果遍历的值是tmp中最大的，就放在tmp最后，否则取代比它大的数中最小的一个；
注意：tmp的结果不一定是符合要求的子序列，但是长度是正确的，比如:[2,3,1,4,5]
```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        if(nums.length<=1) return nums.length;
        int[] tmp = new int[nums.length];
        tmp[0] = nums[0];
        int len = 1;
        for(int n: nums){
            int i = 0;
            while(i<len && tmp[i]<n){
                i++;
            }
            tmp[i] = n;
            if(i==len) len++;
        }
        return len;
    }
}
```
贪心算法+二分查找：上面的方法可以使用二分查找改善时间复杂度因为tmp是递增的，因此可以使用二分查找得到所插入的位置：
```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        if(nums.length<=1) return nums.length;
        int[] tmp = new int[nums.length];
        tmp[0] = nums[0];
        int len = 0;
        for(int n: nums){
            int l=0, r=len;
            while(l<r){
                int m = (l+r)/2;
                if(tmp[m]>=n){
                    r = m;
                }else{l = m+1;}
            }
            tmp[l] = n;
            if(l==len) len++;
        }
        return len;
    }
}
```