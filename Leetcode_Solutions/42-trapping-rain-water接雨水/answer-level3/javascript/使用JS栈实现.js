**在官方代码基础上使用JS栈实现**
```
/**
 * @param {number[]} height
 * @return {number}
 */
function Stack () {
    // 栈中的属性
    this.items = []
    // 栈的相关操作
    // push方法 -- 添加一个元素到栈顶位置
    Stack.prototype.push = function (element) {
    	this.items.push(element)
    }
    // pop方法 -- 移除栈顶元素，同时返回被移除元素
    Stack.prototype.pop = function () {
    	return this.items.pop()
    }
    // peek方法：返回栈顶元素，不对栈做任何修改
    Stack.prototype.peek = function () {
    	return this.items[this.items.length - 1]
    }
    // isEmpty方法
    Stack.prototype.isEmpty = function () {
    	return this.items.length === 0
    }
    // size():返回栈的元素个数
    Stack.prototype.size = function () {
    	return this.items.length
    }
    // toString方法，将栈结构的内容以字符形式返回
    Stack.prototype.toString = function () {
    let resultString = ''
    for (let i=0; i<this.items.length; i++) {
        resultString += this.items[i] + ' '
    }
    	return resultString
    }
}
var trap = function(height) {
    let ans = 0, current = 0;
    let st = new Stack();
    while (current < height.length) {
        while (!st.isEmpty() && height[current] > height[st.peek()]) {
            let top = st.peek();
            st.pop();
            if (st.isEmpty())
                break;
            let distance = current - st.peek() - 1;
            let bounded_height = Math.min(height[current], height[st.peek()]) - height[top];
            ans += distance * bounded_height;
        }
        st.push(current++);
    }
    return ans;
};
```
