```
var findMin = function(nums) {
    let left = 0,right = nums.length-1,mid;
    if(nums.length <= 1) return nums
    //如果最左侧数小于最右侧数，则说明数组是有序的
    if(nums[left] < nums[right]){
      return nums[0] 
    }
    //二分查找
    while(nums[left] >= nums[right]){
        mid =Math.floor((left + right) / 2)
        //对比153题多一个判断：如果左，中，右相等，就遍历寻找最小值
        if(nums[left] == nums[right] && nums[left] == nums[mid]){
            return find(nums,left,right)
        }
        if(nums[mid] > nums[mid+1]){
            return nums[mid+1]
        }else if(nums[mid] > nums[right]){
            left = mid+1
        }else if(nums[mid] < nums[left]){
            right = mid     
        }
    }
    return -1
};
function find(arr,left,right){
    let res = arr[left];
    for(let i=left+1;i<=right;i++){
        if(res > arr[i]){
            res = arr[i]
        }
    }
    return res
}
```
