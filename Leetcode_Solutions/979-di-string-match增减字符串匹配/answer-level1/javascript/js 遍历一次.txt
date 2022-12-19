![image.png](https://pic.leetcode-cn.com/d682adc52a249de3605fd28c61da3427f2e37af7f8eca8aa0784689c0f1759fe-image.png)

### 解题思路
```js
思路：
根据 S 的长度，确定数组的元素 0 - S.length
遍历 S，如果是 'I'，就从左边取一个数，'D'，从右边取一个数
```

### 代码

```javascript
/**
 * @param {string} S
 * @return {number[]}
 */

var diStringMatch = function(S) {
  let min = 0, max = S.length, ans = [];
  
  for (let i = 0, len = S.length; i < len; i++) {
    if (S.charAt(i) === 'I') {
      ans.push( min );
      min++;
    } else {
      ans.push( max );
      max--;
    }
  }
  
  ans.push( min );
  
  return ans;
};
```