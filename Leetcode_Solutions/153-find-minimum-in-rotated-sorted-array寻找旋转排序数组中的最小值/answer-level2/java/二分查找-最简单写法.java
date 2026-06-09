直接拿最后一个元素做对比，免除对索引越界的判断。


```
public int findMin(int[] nums) {
        int target = nums[nums.length-1];
        int l = 0;
        int h = nums.length-1;
        while(l<=h){
            int mid = l +(h-l)/2;
            if(nums[mid] > target){
                l = mid+1;
            }else {
                h = mid-1;
            }
        }
        return nums[l];
    }
```
    
