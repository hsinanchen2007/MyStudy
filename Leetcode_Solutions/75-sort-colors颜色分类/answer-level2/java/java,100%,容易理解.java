
```
    public void sortColors(int[] nums) {
        int len=nums.length;
        int left=0;
        int right=len-1;
        int cur=0;
        while(cur<=right)
        {
            int temp=0;

            if(nums[cur]==0)
            {
                temp=nums[left];
                nums[left]=nums[cur];
                nums[cur]=temp;
                left++;
                //这里cur可以放心++，不必再下一次重新判断这个位置，因为经过交换的位置，cur只可能是1.首先0是不会被换过来的，因为left指的值不会是0（除非left==cur）
                //其次，不可能是2，因为如果2，早在之前几轮就会被换到数组的右侧
                cur++;    
            }else if(nums[cur]==2)
            {
                temp=nums[right];
                nums[right]=nums[cur];
                nums[cur]=temp;
                right--;
                //注意，这里cur不能--，必须重新对cur位置的数字进行判断，因为并不清楚从right位置交换过来的程序是什么，可能是0也可能是1，甚至有可能是2.所以要重新判断
            }else
            {
                cur++;
            }
        }
    }
```
