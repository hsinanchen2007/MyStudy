### 解题思路
一旦遇到两个#的时候可以出栈，并且将栈顶元素换成#
表示遇到两个#可以视为该cur元素已经遍历完成将其置为#
最终的栈中只剩下一个#则为true

### 代码

```javascript
/**
 * @param {string} preorder
 * @return {boolean}
 */
var isValidSerialization = function(preorder) {
    // 遇到两个#就把栈顶的数字换成#
    let arr = preorder.split(',')
    let stack = []

    for(let i = 0; i < arr.length; i++) {
        stack.push(arr[i])
        while(stack[stack.length - 1] == '#' && stack[stack.length - 2] == '#') {
                // #出
                stack.pop()
                stack.pop()
                stack[stack.length - 1] = '#'
        }
                // console.log(stack)
    }


    return stack.length == 1 && stack[0] == '#'
};
```