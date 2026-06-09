```
 public int findMin(int[] nums) {
        //此题思路 第一个数比最后一个小 则未被旋转
        if(nums[0]>=nums[nums.length-1]){
            //对于旋转后的 查查找算法  二分法
            // int left=0,right=nums.length-1;
            // while(left<right){
            //     int mid=(left+right)/2;
            //     if(nums[mid]>nums[right]){
            //         left=mid+1;
            //     }else if(nums[mid]<nums[right]){
            //         right=mid;
            //     }else{
            //         right--;
            //     }

            // }
            // return nums[left];
            
            //但我更喜欢一般的简洁代码
            for(int obj:nums){
                if(obj<nums[0]){
                    return obj;
                }
            }
        }
        return nums[0];
    }
```
