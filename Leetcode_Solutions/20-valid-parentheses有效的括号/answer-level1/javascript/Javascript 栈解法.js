一句话表达核心思想就是:
**如果遇到右括号, 必然与最近的左括号匹配, 否则表达式不合法**

因此开头构建了:
- 所有类型括号的映射表.
- 所有类型的左括号数组.

在指针不断向前推进的过程中:
- 遇到左括号则压入栈中
- 遇到右括号则查表判断是否与栈顶的左括号匹配
  - 匹配则弹出栈顶括号
  - 不匹配则可直接判断表达式不合法

当字符串遍历结束, 检查栈状态:
- 为空则意味着所有左括号都和他的另一半开始了新的人生, 皆大欢喜
- 不为空则代表还有没找到另一半的单身狗, 得再接再厉


```javascript []
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    const couple = new Map([
      ['(', ')'],
      ['[', ']'],
      ['{', '}']
    ]);
    const left = new Array(...couple.keys());

    let idx = 0;
    let stack = [];
    while(idx < s.length) {
      if(left.includes(s[idx])) {
        stack.push(s[idx]);
      } else {
        if(s[idx] === couple.get(stack[stack.length - 1])) {
          stack.pop();
        } else {
          return false;
        }
      }
      idx++;
    }
    return stack.length === 0;
};
```