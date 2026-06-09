### 解题思路
利用快排的思想，每经过一轮排序，pivot 左边的一定是较小的，右边的一定是较大的。

每轮比较之后，得到 left: Array<number>、 pivot: number 和 right: Array<number>

如果 left.length < k => 对于 right 进行递归，找最小的 k - left.length - 1 个数
如果 left.length === k => 返回 left
如果 left.length > k => 找 left 中最小的 k 个数

### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
const leastQSort = (arr, k) => {
    if (arr.length === k) return arr;
    const left = [], right = [];
    const pivot = arr.pop();
    for (let i = 0; i < arr.length; ++i) {
        if (arr[i] <= pivot) {
            left.push(arr[i]);
        } else {
            right.push(arr[i]);
        }
    }
    return left.length < k ? left.concat([pivot]).concat(leastQSort(right, k - left.length - 1)) : leastQSort(left, k); 
}

var getLeastNumbers = function(arr, k) {
    return leastQSort(arr, k);
};
```

### 复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(N)