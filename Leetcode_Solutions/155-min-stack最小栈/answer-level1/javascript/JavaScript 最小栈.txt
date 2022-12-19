解一：

> 用数组保存元素，同时记录当前最小值。不足在于当`pop()`的元素恰好为最小值时要重新`Math.min()`一遍。

```js
var MinStack = function () {
    this.items = [];
    this.min = Infinity;
    return this;
};

MinStack.prototype.push = function (x) {
    this.items.push(x);
    if (x < this.min) this.min = x;
};

MinStack.prototype.pop = function () {
    if (this.items.length) {
        s = this.items.pop();
        if (this.min === s) this.min = Math.min(...this.items);
        return s;
    } else return undefined;
};

MinStack.prototype.top = function () {
    if (this.items.length) {
        return this.items[this.items.length - 1];
    } else return undefined;
};

MinStack.prototype.getMin = function () {
    return this.min;
};
```

解二：

> 双栈，空间换时间，每次`push`保存新的值和新的最小值。类似于Time Machine记录还原点一样。

```js
var MinStack = function () {
    this.items = [];
    this.minStack = [];
    this.count = 0;
    return this;
};

MinStack.prototype.push = function (x) {
    if(!this.count) this.minStack.push(x);
    else if (x < this.minStack[this.count-1]) this.minStack.push(x);
    else this.minStack.push(this.minStack[this.count-1]);
    this.items.push(x);
    this.count++;
};

MinStack.prototype.pop = function () {
    if(!this.count) return undefined;
    this.count--;
    this.minStack.pop();
    return this.items.pop();
};

MinStack.prototype.top = function () {
    if(!this.count) return undefined;
    return this.items[this.count-1];
};

MinStack.prototype.getMin = function () {
    if(!this.count) return undefined;
    return this.minStack[this.count-1];
};
```