### 解题思路
提到有序，必然二分。为了更好的用二分，需要记一个二分法的模板。本题是用了两次模板。

用的模板的特点是左闭右开，就是左面是大于等于，右面是小于。

1. 二分法找到目标值的最左索引 letIndex
2. 如果没找到，直接返回 [-1,-1]
3. 二分法继续找最右索引
4. 返回结果

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function (nums, target) {
    let low = 0;
    let high = nums.length
    while (low < high) {
        let mid = low + Math.floor((high - low) / 2)
        if (nums[mid] >= target) {
            high=mid
        }
        else {
            low=mid+1
        }
    } 
    
    //如果没有找到最左索引，说明值不在数组中，直接返回 [-1,-1]
    if (nums[low] !== target) return [-1, -1]
    let resut = [low]
    high = nums.length
    low=0
    while (low < high) {
        let mid = low + Math.floor((high - low) / 2)
        if (nums[mid] > target) {
            high = mid
        } else {
            low = mid + 1
        }
    }
    //最右索引是 low-1
    resut[1] = low - 1
    return resut
};
```