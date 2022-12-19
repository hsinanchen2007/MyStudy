
栈是一种后进先出的数据结构，我们可以把他想象成一个积木，最后的放在最上面，想要拿到下面的，只能每次从最上面拿。
有效的括号，我们可以发现括号总是成对出现的，我们可以想象把括号符合当做积木。
那么左符号依次叠加，想要拿出来左符号，就需要出现右符号，而且每次只能从积木最上面拿。

PS：  
JS 中可以利用数组实现栈的数据结构，当然现在js也有了栈的数据结构。




```
/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    let stack = [];
    let nums = s.split('');
    // stack.push(nums[0]);
    for(let i = 0; i < nums.length; i++){
        if(nums[i] === '(' || nums[i] === '[' || nums[i] === '{'){
            stack.push(nums[i]);
        }
        if(nums[i] === ')'){
            if(stack.length  && stack[stack.length -1] === '('){
                stack.pop();
            }else{
                return false;
            }
        }
        if(nums[i] === ']'){
            if(stack.length && stack[stack.length -1] === '['){
                stack.pop();
            }else{
                return false;
            }
        }
        if(nums[i] === '}'){
            if(stack.length  && stack[stack.length -1] === '{'){
                stack.pop();
            }else{
                return false;
            }
        }
        // console.log(stack);

    }
    if(stack.length === 0){
        return true;
    }
    return false;
};
```
