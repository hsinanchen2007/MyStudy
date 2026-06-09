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
	// 先判断特殊情况
    if (popped.toString() == pushed.toString()) return true;
	else if (pushed.length == 0) return false;
	else if (popped.length == 0) return false;
// 遍历入栈顺序，每次取到的刚好是栈顶元素
// 每次拿栈顶元素和出栈序列第一个值相同时，栈顶出栈，新的栈顶继续比较   不相同就入栈
    for (var i = 0; i < pushed.length; i ++) {
    	// console.log(i)
    	if (pushed[i] == popped[0]) { // 栈顶元素和出栈序列第一个值相同
    		pushed.splice(i, 1); // 栈顶出栈
    		popped.splice(0, 1); // 出栈序列去掉第一个，这样每次可以都用popped[0]来比较
	    	// console.log(popped)
	    	if (i > 0) i -= 2; // 栈不空的时候 ，减去2是因为下一轮循环时i会+1
	    	else if (pushed.length == 0) return true; // 栈空
            else i--; // 栈空 但是还有 没有入栈的元素
    	}    	
    }
    return false; // 无法栈空时就说明出栈序列有问题
};
```