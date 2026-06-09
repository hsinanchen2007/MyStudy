### 解题思路

### 代码
想了两种方法，一种传统解法，用双重for循环去遍历计数，比较消耗性能
用es6新增方法可以直接过滤出想要的结果，性能提高了
```javascript
/**
 * @param {string} J
 * @param {string} S
 * @return {number}
 */

// 传统方法
var numJewelsInStones = function(J, S) {
    // 声明的同时去除收尾空格并转化为数组
    let newJ = J.trim().split('');
    let newS = S.trim().split('');
    let count = 0;
    // 进行双重遍历，每一次符合时count++
    for (let i = 0; i< newS.length; i++) {
      for (let j = 0; j< newJ.length; j++) {
        if(newS[i] === newJ[j]) {
          count ++
        }
      }
    }
    // 返回结果
    return count;
};

// es6方法
var numJewelsInStones = function (J, S) {
  let newJ = J.split('');
  let newS = S.split('');
  // 直接用filter返回一个新数组，取长度，判断条件是在判断用数组中有没有包含
  return newS.filter(item => newJ.includes(item)).length;
};
```