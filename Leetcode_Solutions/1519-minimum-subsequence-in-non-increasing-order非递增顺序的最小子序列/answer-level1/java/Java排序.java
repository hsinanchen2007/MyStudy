排序后， 从后到前，分别相加左右两边的和，比较大小，输出即可
```
class Solution {
    public List<Integer> minSubsequence(int[] nums) {
        Arrays.sort(nums);
        int n=nums.length,sum1=0,sum2=0;
        if(n==1) return Arrays.asList(nums[0]);

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<i;j++)    sum1+=nums[j];
            for(int j=n-1;j>=i;j--) sum2+=nums[j];
            if(sum2>sum1) {
                 List<Integer> ans = new ArrayList<>();
                for(int j=n-1;j>=i;j--) ans.add(nums[j]);
                return ans;
        }
            sum1=0;sum2=0;
    }
        return null;
    }
}
```
