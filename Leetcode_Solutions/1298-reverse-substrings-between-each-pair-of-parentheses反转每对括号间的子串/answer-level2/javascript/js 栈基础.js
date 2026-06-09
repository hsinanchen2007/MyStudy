![image.png](https://pic.leetcode-cn.com/5ca1572cbda426f6b53a3aaada274bb8329e3b38dbe1b287d4b251f86e4b55e3-image.png)

### 解题思路
```js
参考「typingMonkey」的思路

初始化栈，栈顶元素为 ''
遇到 '(': 向栈顶压入空字符串
遇到 ')': 把栈顶的最后一个元素翻转 + 栈顶倒数第二个元素
遇到 字符: 直接将栈顶最后一个元素与它拼上
```

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */

var reverseParentheses = function(s) {
  let stack = [''];
  
  for (let i = 0, len = s.length; i < len; i++) {
    let c = s.charAt(i);
    if (c === '(') {
      stack.push( '' );
    } else if (c === ')') {
      let last = stack.pop();
      let temp = last.split('').reverse().join('');
      stack[stack.length - 1] += temp;
    } else {
      stack[stack.length - 1] += c;
    }
  }
  
  return stack.pop();
};
```