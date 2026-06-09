### 解题思路
1、计算出所有公因子
2、取最大公因子
### 代码

```javascript
/**
 * @param {string} str1
 * @param {string} str2
 * @return {string}
 */
const gcdOfStrings = (str1, str2) => {
  const isGcd = (str, child) => {
    return str.split(child).join('') === '';
  }

  const len1 = str1.length;
  const len2 = str2.length;

  if (len1 < 0 || len1 > 1000) return '';
  if (len2 < 0 || len2 > 1000) return '';

  const minLen = Math.min(len1, len2);
  const arr = [''];
  for (let i = 1; i <= minLen; i += 1){
    const sub = str1.substring(0,i);
    if (isGcd(str1, sub) && isGcd(str2, sub)){
      arr.push(sub);
    }
  }
  return arr.pop();
};
```