### 解题思路
先对数组进行升序排序，取排序后数组第二位与数组第一位的差，作为初始绝对差，遍历数组，依次将相邻两位做减法，得到的差与初始绝对差做比较，小于初始绝对差，则刷新result数组并push；若相等相等，则push进result数组

### 代码

```javascript
/**
 * @param {number[]} arr
 * @return {number[][]}
 */
var minimumAbsDifference = function(arr) {
    if (arr.length <= 1) return;
    const sortArr = arr.sort((a, b) => a - b);
    const result = [];
    let min = sortArr[1] - sortArr[0];
    let left = 0;
    let right = 1;
    while(right < arr.length) {
        const a = sortArr[right] - sortArr[left];

        if (a < min) {
            result.length = 0;
            result.push([sortArr[left], sortArr[right]]);
            min = a;
        } else if (a === min) {
            result.push([sortArr[left], sortArr[right]]);
        }
        left++;
        right++;
    }
    return result;
};
```