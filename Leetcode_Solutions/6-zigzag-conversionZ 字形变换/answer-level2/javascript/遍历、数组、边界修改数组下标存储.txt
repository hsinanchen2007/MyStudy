思路很简单，就是遍历一次字符串，用一个数组存储，最后导出数组，
边界就是 上下移动的索引即 索引为0的时候增加，索引为 numRows - 1 的时候减少

![微信图片_20200331171927.png](https://pic.leetcode-cn.com/7fff3d38ffb5d116e6979e0389dba56c300d2b3cff6aaf59ae79e45a38bca486-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200331171927.png)


```
var convert = function(s, numRows) {
    if (!s || s.length <= numRows || numRows == 1) {
        return s
    }
    let rows = new Array(numRows).fill("")
    let rowIndex = 0  // 纵向  数组的索引
    let upDown = 1
    for (let i = 0; i < s.length; i++) {
        rows[rowIndex] += s[i]
        rowIndex += upDown
        if (rowIndex == (numRows - 1)) {
            upDown = -1
        }
        if (rowIndex == 0) {
            upDown = 1
        }
    }
    return rows.join("")
};
```

