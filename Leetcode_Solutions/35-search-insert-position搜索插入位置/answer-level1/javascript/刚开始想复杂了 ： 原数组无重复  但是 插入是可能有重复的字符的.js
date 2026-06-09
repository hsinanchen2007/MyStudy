### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    function binary(arr, target){
        let left = 0, right = arr.length - 1;
        let mid = 0;
        while( right - left > 0 ){
            mid = parseInt((right + left) / 2);
            if( arr[mid] == target ){
                return mid;
            }else if( arr[mid] < target ){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        if( arr[left] >= target ){ // >= 插入的比 left 位置的小 或者 相等 插到left原本值的前面
            return left;
        }else{
            return left + 1; // 否则向后加一位 
        }
        
    }
    return binary(nums, target);
};
```