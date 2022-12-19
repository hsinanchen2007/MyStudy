```
/**
 * @param {string} S
 * @return {string}
 */
var removeOuterParentheses = function(S) {
  let string = [...S]   // 字符串转数组
  let stack = []    // 声明栈
  let ret = ''  // return 内容
  let startIndex = 0 // 起始下标
  string.forEach((e, i) => {
    if(stack.length>=1 && e !== stack[stack.length-1]){
      stack.pop()
      if(!stack.length){
        ret += S.slice(startIndex+1, i)
        startIndex = i+1
      }
    }else{
      stack.push(e)
    }
  })
  return ret
};
```
题目一开始比较混乱，难以理解
我的理解就是类似： 将二维数组拆成一位数组然后拼接 一维数组再拆就没了。。。 这也是示例提示出来的


1.主要通过栈来遍历按序将括号入栈，如栈前检查是否该括号和栈顶元素一样，如果一样则入栈，不一样则出栈一个 
2.若栈空了代表有嵌套出现即类似多维数组，需要进行拆分操作了
3.拆分即 将原数组的startindex+1的位置到当前位置进行截取 去除了外层的一层括号，重置startindex到下一位
