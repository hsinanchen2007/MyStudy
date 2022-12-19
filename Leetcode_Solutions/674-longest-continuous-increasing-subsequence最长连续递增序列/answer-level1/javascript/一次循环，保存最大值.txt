### 方法一
思路：使用两个下标start和end，分别记录每一次找到的递增序列开始和末尾，使用max函数保持最大长度即可
注意边界的处理，每次一段升序结束后start = end + 1;

### 代码

```javascript
var findLengthOfLCIS = function(nums) {
    if (!nums.length) return 0;
    let max = 1, start = 0, end = 0;

    while (start < nums.length - 1) {
        if (nums[start] >= nums[start + 1]) {
            start++;
            continue;
        }
        end = start;
        while (end + 1 < nums.length && nums[end] < nums[end + 1]) end++;

        max = Math.max(max, end - start + 1);
        start = end + 1;
    }
    return max;
};
```
### 方法二
思路：每次当后面的数小于前面的数时，直接count++,否则重置为1，最终保存的最大count即是结果
### 代码
```
var findLengthOfLCIS = function(nums) {
    if (!nums.length) return 0;
    let res = 1, count = 1;

    for (let i = 0; i < nums.length - 1; i++) {
        if (nums[i] < nums[i + 1]) {
            count++;
        } else {
            count = 1;
        }
        res = res > count ? res : count;
    }
    return res;
}
```