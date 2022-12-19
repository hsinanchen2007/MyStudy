### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {

    let l = findLeftIndex(nums, target),
        r = findRightIndex(nums, target)

    return r - l + 1
};

/** * 经典二分查找算法的一种变型! 即如果遇到 == 情况下继续向左侧查找 */
const findLeftIndex = (nums, target) => {
    let l = 0, r = nums.length - 1
    while (l <= r) { 
        let mid = Math.trunc((l + r) / 2)
        if (target <= nums[mid]) r = mid - 1
        else l = mid + 1 
    }
    return l
}

/**
 * 同理
 */
const findRightIndex = (nums, target) => {
    let l = 0, r = nums.length - 1
    while (l <= r) { 
        let mid = Math.trunc((l + r) / 2)
        if (target >= nums[mid]) l = mid + 1
        else r = mid - 1 
    }
    return r
}
```