解题思路：
把字符串按数字分组切割，如：['00', '11', '00', '11']
相邻的两组数据组合，长度较短的数据长度即为这组数据可能的数据次数
如：
00011，可能情况只能是0011， 01两个
0001111，可能情况只能是000111，0011，01三个

```javascript
/**
 * @param {string} s:'00110011'
 * @return {number}
 */
const countBinarySubstrings = s => {
  let number = 0;
  const arr = s.match(/0+|1+/g);    // 把字符串切割成['00', '11', '00', '11']这样的数组

  for(let i = 0, len = arr.length; i < len - 1; i++){
    number += Math.min(arr[i].length, arr[i+1].length);     // 相邻比较，长度更短的则为这一组的出现次数
  }

  return number;
}
```
