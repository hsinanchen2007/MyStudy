### 解题思路
利用map对罗马数字进行映射关系
看了大佬的解题 才理解罗马数字的左右关系

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
const romanToInt = s => {
    let map = new Map([['I', 1], ['V', 5], ['X', 10], ['L', 50], ['C', 100], ['D', 500], ['M', 1000]])
    let res = 0;
    for (let i = 0; i < s.length; i++) {
        let left = map.get(s[i]);
        let right = map.get(s[i + 1]);
        res += left < right ? -left : left
    }
    return res
};
```