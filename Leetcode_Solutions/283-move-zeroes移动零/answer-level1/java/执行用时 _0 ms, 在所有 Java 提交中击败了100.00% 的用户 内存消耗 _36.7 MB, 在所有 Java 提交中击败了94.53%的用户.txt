记录下0的个数，遇到非0元素即与其前sum个元素换，该元素一定为0.
```
class Solution {
    public void moveZeroes(int[] nums) {
        int sum=0;
        for(int i=0;i<nums.length;i++)
        {
            if(nums[i]==0){sum++;}
            else
            {
                int temp=nums[i];
                nums[i]=nums[i-sum];
                nums[i-sum]=temp;
            }
        }
    }
}
```
