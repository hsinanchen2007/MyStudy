![image.png](https://pic.leetcode-cn.com/0eb7f79ec0d604bb305f4e08e66810db350bc2553af64dbc141b34d86c51dedd-image.png)

### 解题思路
```javascript
思路：本质就是看 balloon 出现了几次，注意有字母出现了两次，要除以2
即：
Math.min( num['b'], nums['a'], num['l'] / 2, nums['o'] / 2, num['n'] )
```

### 代码

```javascript
/**
 * @param {string} text
 * @return {number}
 */

var maxNumberOfBalloons = function(text) {
  let obj = { b: 0, a: 0, l: 0, o: 0, n: 0 }, min = Infinity;
  
  for (let i = 0, len = text.length; i < len; i++) {
    let c = text.charAt(i);
    if (obj[ c ] !== undefined) {
      obj[ c ]++;
    }
  }
  
  for (let key in obj) {
    if ('lo'.indexOf( key ) > -1) {
      min = Math.min( Math.floor(obj[key] / 2), min );
    } else {
      min = Math.min(obj[key], min);
    }
  }
  
  return min === Infinity ? 0 : min;
};
```