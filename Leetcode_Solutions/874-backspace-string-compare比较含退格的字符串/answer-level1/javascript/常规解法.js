### 解题思路
- 封装一个方法，先将字符串转换为数组，然后申明一个空数组，遇到#就执行pop(),否则就就执行push().
- 然后分别将S和T代入此方法。

```javascript
var backspaceCompare = function(S, T) {
  if(S === T) {
    return true;
  }

  let s = deal(S);
  let t = deal(T);

  if (s === t) {
    return true;
  } else {
    return false;
  }

  function deal(str) {
    let arr = str.split("");
    let result = [];

    arr.forEach((item) => {
      if (item === '#') {
        result.pop();
      } else {
        result.push(item);
      }
    })

    return result.join('');
  }
};
```