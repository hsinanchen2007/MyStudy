执行用时 : 72 ms, 在所有 JavaScript 提交中击败了 96.43% 的用户
内存消耗 : 33.7 MB , 在所有 JavaScript 提交中击败了 100.00% 的用户

```javascript []
var binsert = function(arr, l, r, n) {
    if (arr[r] <= n) {
        arr.splice(r+1, 0, n);
    } else if (l === r || arr[l] >= n) {
        arr.splice(l, 0, n);
    } else {
        var m = Math.floor((l + r) / 2);
        if (arr[m] <= n && arr[m+1] >= n) {
            arr.splice(m+1, 0, n);
            return;
        } else if (arr[m] >= n) {
            binsert(arr, l, m, n);
        } else {
            binsert(arr, m, r, n);
        }
    }
}

var lastStoneWeight = function(stones) {
    stones.sort((a, b) => a - b);
    while (stones.length > 1) {
        let first = stones.pop(),
            second = stones.pop();
        if (first !== second) {
            binsert(stones, 0, stones.length-1, first-second);
        }
    }
    if (stones.length) {
        return stones[0];
    }
    return 0;
};
```

