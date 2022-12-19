### 解题思路
1、判断异常情况，①.空数组，返回空字符串“”，②.数组长度为1，返回第一个元素。
2、数组长度大于1
  2.1 拿到数组中最短长度的元素，作为最长前缀的目标target。与其他元素去比对。
  2.2 数组中其他元素依次裁剪target相同长度的串，用every方法，依次与target进行比对，如果都相等，target就是最终结果。如果有不相等，target长度减1作为新的target,再去比对。以此类推，直到所有元素的裁切结果都等于target。target就是最长前缀。
![niao.png](https://pic.leetcode-cn.com/910524c5ffb3511c02a6b168885267932c4aa14e6d5382ae5eaceadb0ba5dfe6-niao.png)

### 代码

```javascript
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    if (strs.length === 1) {return strs[0];}
    if (strs.length === 0) {return '';}
    let minLenItem = strs[0];
    for (let i = 1; i < strs.length; i++) {
      minLenItem = strs[i].length < minLenItem.length ? strs[i] : minLenItem;
    }
    let maxPre = '';
    for (let j = minLenItem.length; j > 0; j--) {
      let splitItem = minLenItem.slice(0, j);
      let isRight = strs.every(item => {
        return item.slice(0, j) === splitItem;
      });
      if (isRight) {
        maxPre = splitItem;
        break;
      }
    }
    return maxPre;
};
```