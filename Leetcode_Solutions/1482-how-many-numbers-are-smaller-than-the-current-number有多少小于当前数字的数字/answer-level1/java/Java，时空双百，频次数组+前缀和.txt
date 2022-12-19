
```
class Solution {
    public int[] smallerNumbersThanCurrent(int[] nums) {
        int n=nums.length;
        int[] ans=new int[n];
        int[] cnt=new int[101];
        for(int i=0;i<n;i++){
            cnt[nums[i]]++;//记录每个数字频次
        }
        for(int i=1;i<cnt.length;i++){
            cnt[i]+=cnt[i-1];//cnt[i]为小于等于nums[i]的个数，cnt[i-1]则为小于nums[i]的个数
        }
        for(int i=0;i<n;i++){
            if(nums[i]>0){//没有小于零的数
                ans[i]=cnt[nums[i]-1];
            }
        }
        return ans;
    }
}
```
