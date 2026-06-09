### 解题思路
类似于20题的压栈的方法，但是这次压入栈中的对象有所不同，它有两个属性，即type和index。
type表示该对象的类型（左括号还是右括号）。
index表示该对象的下标值。
此题解中我在栈头和栈位各压入了一个空type的对象作为辅助，方便下面计算距离。
遍历字符串将所有有效括号去掉，则栈中仅剩无效的括号。
各无效括号的下标值和栈头下标、栈尾下标是我们最后计算时使用的数据，我们只需要从头遍历栈，查找出距离最大的两个相邻对象即可。
### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var longestValidParentheses = function(s) {
    if(s.length == 0) return 0
    var temp = [{type: 0, index: 0}]
    max = 0
    num = 0
    for(i=0;i<s.length;i++){
        if(s[i] == '(') temp.push({type: '(', index: i+1})
        //这里压入栈中的index是i+1，原因是在最开始我在栈头压入了一个辅助对象，该辅助对象的index是0。
        else if(s[i] == ')' && temp[temp.length-1].type == '(') temp.pop()
        else temp.push({type: ')', index: i+1})
    }
    temp.push({type: 0, index: s.length+1})
    for(j=0;j<temp.length-1;j++){
        num = temp[j+1].index - temp[j].index - 1
        //因为要计算两个相邻对象之间的括号数量，因此再-1
        if (num>max) max = num
    }
    return max
};
```