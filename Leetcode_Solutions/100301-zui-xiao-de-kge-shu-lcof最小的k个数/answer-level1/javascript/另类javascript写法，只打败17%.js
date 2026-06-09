### 解题思路
主要就是维护一个k长度的数组
每次都找到新元素在这个数组中的生序位置，再判断是否要插入到数组中
最后返回这个数组

### 代码

```javascript
var getLeastNumbers = function (arr, k) {
    if (!arr.length && arr.length === 0) return [];
    const cur = [];
    cur[0] = arr[0];
    for (let i = 1; i < arr.length; i++) {
        const pos = position(arr[i]);
        pos !== -1 ? cur.splice(pos, 0, arr[i]) : null;
        if (cur.length > k) cur.pop();
    }

    return cur;

    function position(value) {
        const len = cur.length;
        let i = 0;
        for (; i < len; i++) {
            if (value < cur[i]) break;
        }
        return i < k ? i : -1;
    }
};
```