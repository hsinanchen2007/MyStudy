![TIM截图20190815093511.png](https://pic.leetcode-cn.com/529fedf41814b69f7fdacf5eb3a0968d7f9b377709b698c67c0a6e43685e67af-TIM%E6%88%AA%E5%9B%BE20190815093511.png)
```
思路：

用额外变量保存最小值，和使用辅助栈保存最小值的思路类似
/**
 * initialize your data structure here.
 */
var MinStack = function () {
    this.item = [];
    this.min = Infinity;
    return this
};

/** 
 * @param {number} x
 * @return {void}
 */
MinStack.prototype.push = function (x) {
    this.item.push(x)
    this.min = Math.min(this.min, x)
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function () {
    if(!this.item.length)
    return 0
    let s = this.item.pop()
    if(this.min === s)
    this.min = Math.min(...this.item)
};

/**
 * @return {number}
 */
MinStack.prototype.top = function () {
    let len = this.item.length
    if (!len)
        return 0
    return this.item[len-1]
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function () {
    return this.min
};

/** 
 * Your MinStack object will be instantiated and called as such:
 * var obj = new MinStack()
 * obj.push(x)
 * obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.getMin()
 */
```
