### 解题思路
先给字符串排序
然后（正序或倒序）递归每一个不同的

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var sortString = function (s) {
    s = s.split('').sort((a, b) => a.charCodeAt() - b.charCodeAt());
    function handler(ss, flag) {
        let res = '';
        let current = '';
        if (ss.length === 0) return '';
        ss = ss.filter((item) => {
            if (item !== current) {
                !flag && (res = res + item);
                flag && (res = item + res);
                current = item;
                return false;
            }
            return true
        })
        flag = !flag;
        return res + handler(ss, flag);
    }
    return handler(s, false)
};
```