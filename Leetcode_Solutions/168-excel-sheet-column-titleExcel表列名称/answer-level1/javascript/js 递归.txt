### 解题思路
此处撰写解题思路
将输入转化为nums数组，num[1, 26]。
例如：
1 -> [1]
26 -> [26]
27 -> [1, 1]
52 -> [1, 26]
...

### 代码

```javascript
/**
 * @param {number} n
 * @return {string}
 */
var convertToTitle = function(n) {
    const mod26 = (num) => {
        if (num <= 26) { return [num]; }
        if (num % 26 === 0) {
            return mod26((num / 26) -1).concat([26]);
        }
        return mod26(parseInt(num / 26)).concat([num % 26]);
    }
    return mod26(n).map(num => String.fromCharCode(num + 65 - 1)).join('');
};
```