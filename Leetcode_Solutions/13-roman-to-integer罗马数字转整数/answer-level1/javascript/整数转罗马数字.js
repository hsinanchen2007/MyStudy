leetcode小白。
我的解题思路：
1. 定义一个对象，键和值分别对应罗马数字和阿拉伯数字
2. 进行遍历（害，我只会for循坏）
3. 如果前一位的罗马数字所代表的阿拉伯数字比后面的大，则将他们相减的差和sum累加。同时把指针移到后面两位。
4. 如果按顺序的，则累加

```js
var romanToInt = function(s) {
  const ROME = {
    I : 1 ,
    V : 5 ,
    X : 10 ,
    L : 50 ,
    C : 100 ,
    D : 500 ,
    M : 1000
  }
  let sum = 0
  for(let i = 0 ; i < s.length; i++) {
    if (ROME[s[i]] - ROME[s[i+1]] < 0) {
      sum += ROME[s[i + 1]] - ROME[s[i]]
      i++
    } else {
      sum += ROME[s[i]]
    }
  }
  return sum
};
```
嗯，性能很差
![image.png](https://pic.leetcode-cn.com/47698b8176ebdf85fb3d694a8813cb7b51d7556336c46a0681b8683362471e97-image.png)
