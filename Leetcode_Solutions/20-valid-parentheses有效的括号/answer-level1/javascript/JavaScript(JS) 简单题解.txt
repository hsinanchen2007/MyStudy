### 解题思路
利用后进先出的栈来判断
![扫码_搜索联合传播样式-标准色版.png](https://pic.leetcode-cn.com/13e51d67321de7398d6786dd68a1e10a06a04f2f69a05cce6692c22b484e7118-%E6%89%AB%E7%A0%81_%E6%90%9C%E7%B4%A2%E8%81%94%E5%90%88%E4%BC%A0%E6%92%AD%E6%A0%B7%E5%BC%8F-%E6%A0%87%E5%87%86%E8%89%B2%E7%89%88.png)

### 代码

```javascript
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
    let stack = [];
    map = new Map([[')', '('], [']', '['], ['}', '{']]);
    for (let i = 0; i < s.length; i++) {
        if (!map.has(s[i])) {
            stack.push(s[i]);
        } else {
            if (!stack.length || map.get(s[i]) !== stack.pop()) {
                return false
            }
        }
    }
    return stack.length === 0
};
```