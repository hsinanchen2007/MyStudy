执行用时 :148 ms, 在所有 JavaScript 提交中击败了94.75%的用户
```javascript []

var stock;
var minStock;
var MinStack = function() {
   stock=[];
   minStock=[];
};

/** 
 * @param {number} x
 * @return {void}
 */
MinStack.prototype.push = function(x) {
    stock.push(x);
    if(minStock.length==0)
        minStock.push(x);
    else {
        if(x<=minStock[minStock.length-1])
         minStock.push(x);
    }
};

/**
 * @return {void}
 */
MinStack.prototype.pop = function() {
     
    if(minStock[minStock.length-1]==stock[stock.length-1])
        minStock.pop();
     stock.pop();
};

/**
 * @return {number}
 */
MinStack.prototype.top = function() {
    return stock[stock.length-1];
};

/**
 * @return {number}
 */
MinStack.prototype.getMin = function() {

    return minStock[minStock.length-1];
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

