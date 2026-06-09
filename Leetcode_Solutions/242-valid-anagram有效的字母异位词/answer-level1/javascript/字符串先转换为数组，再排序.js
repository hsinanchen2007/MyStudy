### 解题思路
1.先通过split将字符串转换为数组
2.再执行sort将数组进行排序
3.再把数组join转换为字符串
4.返回2个字符串的强对比

### 代码

```javascript
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function(s, t) {
   return s.split('').sort().join('') === t.split('').sort().join('')
};
```