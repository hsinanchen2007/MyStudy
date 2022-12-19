### 解题思路
1.看代码注释
### 代码

```javascript
/**
 * @param {number[]} pushed
 * @param {number[]} popped
 * @return {boolean}
 */
var validateStackSequences = function(pushed, popped) {
    //辅助栈
    const stack = [];
    //指向poped当前的下标
    let index = 0;
    //把pushed的元素一个一个入栈
    for(let i = 0,len=pushed.length-1;i<=len;i++){
        stack.push(pushed[i])
        //把入栈的当前元素和pushed当前指向的元素进行对比
        //相等话就把辅助栈出栈
        //pushed下标往右移动
        while(stack.length !== 0 && stack[stack.length-1] === popped[index]){
            stack.pop()
            index++
        }
    }
    //如果stack为空，说明符合题目
    return !stack.length
};
```