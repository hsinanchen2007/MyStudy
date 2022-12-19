思路 
用一个变量来存储层级，把层级的奇数和偶数分开放到AB里，只需要循环一次，当遇到左括号　层级加一，判断层级的奇偶，再判断如果是右括号层级减一，右括号要后判断，因为要在把一对同一层级的括号放在一组
```
var maxDepthAfterSplit = function(seq) {
   let level = 0
   let result = Array(seq.length).fill(0)
   let list = seq.split('')
   for(let i=0; i<list.length; i++) {
       if(list[i] === '(') {
           level++
       }
       if(level%2===0) {
           result[i] = 1
       }
       if(list[i] === ')') {
           level--
       }
   }
   return result
};
```
