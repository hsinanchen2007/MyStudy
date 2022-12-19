### 解题思路
粗暴且万能的方法

### 代码

```javascript
/**
 * @param {string} J
 * @param {string} S
 * @return {number}
 */
var numJewelsInStones = function (J, S) {
    const reg = new RegExp(`[${J}]`, "g")
    return S.split(reg).length - 1
};
```