### 解题思路
一种深度优先遍历的方式，回溯思想，类似题目 **组合总和**, **组合总和II**，
写回溯比较关键的就在于确定回溯的条件来设置参数和编写逻辑，模板都类似。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
    let retVal = [];
    if (!nums)
        return retVal;
    if (nums.length === 1)
        return [nums];

    const arrSwap = function(arr, i, j) {
        let tmp = arr[i];
        arr[i] = arr[j];
        arr[j] = tmp;
    }

    const backtrace = function(len, start, arr, res) {
        if (start === len) {
            res.push(arr.slice());
            return;
        }

        for (let i = start; i < len; i++) {
            arrSwap(arr, start, i);
            backtrace(len, start + 1, arr, res);
            arrSwap(arr, start, i);
        }
    }

    backtrace(nums.length, 0, nums, retVal);
    return retVal;
};
```