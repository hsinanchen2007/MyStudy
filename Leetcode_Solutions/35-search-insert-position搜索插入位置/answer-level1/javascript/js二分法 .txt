![image.png](https://pic.leetcode-cn.com/6f149d5b00c751b33231b517040034a95ada04f8573c07d03864a53dfac016ad-image.png)


```
var searchInsert = function(nums, target) {
    let low=0;
    let high=nums.length-1;
    if(target>nums[high]) return high+1;
    if(target<nums[0]) return 0;
    while(low<=high){
        let mid=Math.floor((low+high)/2);
        if(nums[mid]===target || (nums[mid-1]<target && nums[mid]>target)){
            return mid;
        }else if(nums[mid+1]>target && nums[mid<target]){
            return mid+1
        }else if(nums[mid]>target){
            high=mid-1;
        }else if(nums[mid]<target){
            low=mid+1;
        };
    }
};
```
