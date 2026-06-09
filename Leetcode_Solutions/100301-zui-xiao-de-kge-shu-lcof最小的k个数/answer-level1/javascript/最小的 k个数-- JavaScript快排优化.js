![image.png](https://pic.leetcode-cn.com/f18af6e4455bdf81b0043c42082e066c787f724137d53b8b16ce1dc4c22612d0-image.png)


```
var getLeastNumbers = function (arr, k) {
    quickSort(arr, 0, arr.length - 1, k);
    return arr.slice(0, k);
};
function quickSort(arr, l, r, k) {
    var flag = arr[r];
    // 在这里进行优化，如果 l 为 k 的话，代表数组以 k 为界限的左右两边已经排好序
    if(l === k) return;
    var p = l;
    for (var i = l; i <= r; i++) {
        if (arr[i] <= flag) {
            var temp = arr[i];
            arr[i] = arr[p];
            arr[p] = temp;
            p++;
        }
    }
    if (l < p - 2) quickSort(arr, l, p - 2, k);
    if (p < r) quickSort(arr, p, r, k);
}
```
