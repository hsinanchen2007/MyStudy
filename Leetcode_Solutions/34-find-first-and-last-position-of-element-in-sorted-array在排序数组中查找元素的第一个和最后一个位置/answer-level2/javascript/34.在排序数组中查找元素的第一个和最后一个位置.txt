### 解题思路
题目要求时间复杂度是(logn) 所以采用二分法查找
此处的查找跟普通二分法查找的不同之处在于数组中的目标值可能存在多个；
当target==nums[mid]时，下标mid前或者后都可能存在于target相等的数，需要从下标mid依次向前或者向后判断与target相等的数据；


### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
    let low =0
    let high = nums.length-1;
    let list = []
    while(low<high){
        let mid = Math.floor((low+high)/2)
        if(nums[mid]>target){
            high = mid-1
        }else if(nums[mid]<target){
            low = mid+1
        }else{
            list[0] = mid;
            list[1] = mid;
            while(nums[mid-1]==target){
                list[0] = mid-1
                mid--
            }
            mid = list[1]
            while(nums[mid+1]==target){
                list[1] = mid+1;
                mid++
            }
            return list;
        }
    }
    return (nums[low]==target?[low,low]:[-1,-1])
};
```