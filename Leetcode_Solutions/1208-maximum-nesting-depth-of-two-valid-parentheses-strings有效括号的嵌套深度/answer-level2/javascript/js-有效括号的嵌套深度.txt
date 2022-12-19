### 解题思路
- 用变量模仿一个栈来记录
- 然后将有效括号的字符串分割为数组,方便遍历操作
- 遍历数组,遇到'('则进栈, 然后记录当前栈的深度
- 遇到')' 先记录深度,然后出栈操作
- 个人理解 关于%2 的操作 要得到深度最小,所以在遇到更深 例如'((()))' 则进行拆分的操作吧

### 代码

```javascript
/**
 * @param {string} seq
 * @return {number[]}
 */
var maxDepthAfterSplit = function(seq) {
    const dep = []  // 用变量模仿一个栈来记录
    const arr = seq.split("") // 将括号划分为数组方便遍历
    return arr.map(v => { 
        if (v === '(') { // 如果当前value 为'(' 
            dep.push(v) // 将( 压入栈内
            return dep.length%2 // 返回当前深度 %2
        } else { // 遇到了')'就执行出栈
            const ans = dep.length%2  // 记录当前深度
            dep.pop() // 执行出栈
            return ans
        }
    })
};
//个人理解 关于%2 的操作 要得到深度最小,所以在遇到更深 例如'((()))' 则进行拆分的操作吧

```