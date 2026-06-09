### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
const reverse = x => {
  const flag = x < 0 ? true : false;
  x = flag ? -x : x;
  x = String(x)
    .split('')
    .reverse()
    .join('')
    .replace(/^0+/g, '');

  x = flag ? -+x : +x;
  if (x > Math.pow(2, 31) - 1 || x < -Math.pow(2, 31)) return 0;
  else return x;
};
```