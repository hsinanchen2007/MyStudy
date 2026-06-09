### 解题思路

一开始想把它当成个数组来弄, 找出一个数组的所有集合, 是可以找出来, 但是时间超出限制
因为 这题只有 两个符号  用数组的方法会重复生成好多

先 生成所有 字符串, 在筛选符合条件的
```js
// 如 n = 2, 第一个字符肯定是 ( 

      1      2     3     4
      (  =>  (  =>  )  => )           (())
         =>  )  =>  (  => )           ()()
                =>  )  => (           ())(

// 得出 3 种,  再筛选 出符合的, 
// 筛选也很简单, 遍历这个字符串  遇到 ) 加 -1  遇到 ( 加1, 当为负数时不符合跳出循环

```

### 代码

```javascript
/**
 * @param {number} n
 * @return {string[]}
 * 执行用时 :72 ms, 在所有 JavaScript 提交中击败了45.08%的用户
   内存消耗 :37.1 MB, 在所有 JavaScript 提交中击败了18.42%的用户
 */
var generateParenthesis = function(n) {
  let list = []
  function sum(str, num, ln, rn){
    if(str.length === 2 * n - 1){     // 其实到最后一次就没必要继续执行下去了, 直接把剩下那个加上就行了
      str += ln ? '(' : ')', list.push(str)
      return
    } 
    num >= 0 && ln > 0 ? (str += '(', ln--) : (str += ')', rn--)
    rn > 0 && sum(str, -1, ln, rn)
    ln > 0 && sum(str, 1, ln, rn)
  }
  sum('', 0, n, n)
  return list.filter(item => isValid(item))
};

// 判断是否有效
function isValid(str){
  let sum = 0
  for(let prop of str){
    sum += prop ===')' ? -1 : 1
    if(sum < 0) return false
  }
  return true
}
```