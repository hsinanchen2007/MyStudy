### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} pushed
 * @param {number[]} popped
 * @return {boolean}
 */
var validateStackSequences = function(pushed, popped) {
    //check stack permutation
    if(pushed.length == 0) return true;
    let stack = [];
    let j = 0;//记录popped
    for(let i = 0; i < pushed.length; i++){
        stack.push(pushed[i]);//每次将pushed的元素push入栈
        while(stack[stack.length-1] == popped[j] && j < pushed.length){
            stack.pop();//每当栈顶元素与当前需要popped元素相同，pop
            j++;
        }
    }
    if(stack.length == 0) return true;//若辅助栈stack为空，则true
    while(j < pushed.length){//若不为空，则依次检查栈顶元素与popped元素顺序是否一致
        if(stack[stack.length-1] == popped[j]){
            stack.pop();
            j++;
        }else return false;
    }
    return true;
};
```