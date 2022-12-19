### 解题思路
完全可以使用长度26位的数组来存储字符出现的次数

### 代码

```javascript
var firstUniqChar = function(s) {
    let arr = new Array(26).fill(0);

    for (let c of s) {
        arr[c.charCodeAt() - 97] += 1;
    }

    for (let c of s) {
        if (arr[c.charCodeAt() - 97] == 1) {
            return c;
        }
    }
    return ' ';
};
```