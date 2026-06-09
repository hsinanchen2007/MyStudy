```
class Solution {
    public int wiggleMaxLength(int[] nums) {
        if(nums.length==0)
            return 0;
        int []dp=new int[nums.length+1];
        
        int index=0;
        for(int i=1;i<nums.length;i++){ // 双指针法 去除nums中连续重复数字
            if(nums[i]!=nums[i-1]){
                index++;
                nums[index]=nums[i];
            }
                
        }

        // 退出循环后 index是nums末尾元素的索引
        if(index<=1)
            return index+1;
        Arrays.fill(dp,0);
        dp[0]=1;
        dp[1]=2;
        for(int i=2;i<=index;i++){
            if((nums[i]-nums[i-1])*(nums[i-1]-nums[i-2])<0)
                dp[i]=dp[i-1]+1;
            else
                dp[i]=dp[i-1];
        }
        return dp[index];
    }
}
```
