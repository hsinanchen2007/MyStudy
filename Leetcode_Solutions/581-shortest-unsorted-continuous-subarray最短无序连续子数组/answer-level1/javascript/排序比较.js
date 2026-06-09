### 解题思路
先排序，然后找出最左边和最右边不相同两个数下标即可

### 代码

```javascript
var findUnsortedSubarray = function(nums) {
    let arr = [...nums], start = 0, end = 0;
    nums.sort((a, b) => a - b), i = 0, j = nums.length - 1;

    while (i < nums.length) {
        if (nums[i] != arr[i]) {
            start = i;
            break;
        }
        i++;
    }

    while (j >= 0) {
        if (nums[j] != arr[j]) {
            end = j;
            break;
        }
        j--;
    }
    return i == nums.length ? 0 : end - start + 1;
};
```