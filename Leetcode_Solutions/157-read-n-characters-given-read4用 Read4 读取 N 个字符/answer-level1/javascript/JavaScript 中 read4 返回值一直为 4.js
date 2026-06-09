### 解题思路
需要注意的一点是，在 JavaScript 中，`read4` 这个函数返回值一直是 4，所以需要自己判断最后一次读取字符的个数，还有不能使用 concat 函数，也不能使用扩展运算符进行 buf 的合并

### 代码

```javascript

var solution = function(read4) {
    
    return function(buf, n) {
        let count = 0
        lastRead = n % 4
        while (count < n) {
            let tBuf = []
            let i = read4(tBuf)
            if (count + i > n) {
                i = lastRead
            }
            for (let j = 0; j < i; j++) {
                buf[count++] = tBuf[j]
            }
            if (i < 4) {
                break
            }
        }
        return count
    };
};
```