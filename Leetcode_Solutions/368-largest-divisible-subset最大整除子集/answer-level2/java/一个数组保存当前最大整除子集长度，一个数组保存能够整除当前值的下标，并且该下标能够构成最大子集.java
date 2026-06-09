```
class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
      List<Integer> ans=new ArrayList<>();
        if (nums.length==0){
            return ans;
        }
        int[] dp=new int[nums.length];
        int[] dp2=new int[nums.length];
        Arrays.fill(dp,1);
        Arrays.fill(dp2,-1);
        Arrays.sort(nums);
        for (int i=1;i<nums.length;i++){
            for (int j=0;j<i;j++){
                if (nums[i]%nums[j]==0){
                    if (dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;//dp[i]表示以当前值为结尾时的最大整除子集的长度
                        dp2[i]=j;//dp2[i]表示上一个能被自己整除的且整除子集长度最大的 下标
                    }
                }
            }
        }
        int index=0;
        for (int i=1;i<nums.length;i++){
            if (dp[i]>dp[index]){
                index=i;
            }
        }
        while (index!=-1){
            ans.add(nums[index]);
            index=dp2[index];
        }
        return ans;
    }
}
```
