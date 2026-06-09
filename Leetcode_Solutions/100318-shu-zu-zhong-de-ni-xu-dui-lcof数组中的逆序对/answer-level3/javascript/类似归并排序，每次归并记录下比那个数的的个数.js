### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var reversePairs = function (nums) {
    return merge_Sort(nums, 0, nums.length - 1);
};
function merge_Sort(arr, l, r) {
    if (l >= r) return 0;
    // 选取中点
    let mid = l + r >> 1;
    // 递归处理左右两边
    let res = merge_Sort(arr, l, mid) + merge_Sort(arr, mid + 1, r);
    // 归并寻找跨越区间的
    let i = l;
    let j = mid + 1;
    let temp = [];
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) temp.push(arr[i++]);
        else {
            temp.push(arr[j++]);
            res += mid - i + 1;
        }
    }
    while (i <= mid) temp.push(arr[i++]);
    while (j <= r) temp.push(arr[j++]);
    for (i = l, j = 0; i <= r; i++ , j++) arr[i] = temp[j];
    return res;
}
```