```
/**
 * initialize your data structure here.
 * 空间换时间
 */
var MinStack = function() {
    this.data = [];
    this.helper = [];
};

/**
 * @param {number} x
 * @return {void}
 */
MinStack.prototype.push = function(x) {
    this.data.push(x);
    let helperLen = this.helper.length;
    this.helper.push(helperLen ? x < this.helper[helperLen - 1] ? x : this.helper[helperLen - 1] : x)
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function() {
    if (this.data.length) {
        this.data.length = this.data.length - 1;
        this.helper.length = this.helper.length - 1;
    }
};

/**
 * @return {number}
 */
MinStack.prototype.top = function() {
    return this.data[this.data.length - 1];
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function() {
    return this.helper[this.helper.length - 1];
};
```