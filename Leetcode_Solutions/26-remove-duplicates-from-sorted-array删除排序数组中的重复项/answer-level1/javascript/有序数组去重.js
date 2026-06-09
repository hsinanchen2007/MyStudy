## 快慢指针

- 时间复杂度：O(n), one pass
- 空间复杂度：O(1), 一共用了3个临时变量 

```
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function (nums) {
    if (nums.length === 0) return 0;

    let res = nums[0], slow = 1;
    
    for (let fast = 1; fast < nums.length; fast++) {
        if (res === nums[fast]) continue;
        res = nums[fast];
        nums[slow] = res;
        slow += 1;
    }
    return slow;
};
```
