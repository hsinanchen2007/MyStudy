### 解题思路
假设有qu1和qu2两个队列，只需要保证qu1里面始终只有一个元素即可，往qu1里面push的时候，就将qu1多余的元素就往qu2中放；pop的话，就将qu1中唯一元素取出来，然后，将qu2中元素在qu1中全部走一遍，除最后一个元素，其他元素全部回到qu2中。

![image.png](https://pic.leetcode-cn.com/1d93354623026adf57e5eacf9e2a89128efede7a5a728acfffb176b308398cd2-image.png)

### 代码

```javascript
/**
 * Initialize your data structure here.
 */
var MyStack = function() {
    this.qu1=[];
    this.qu2=[];
};

/**
 * Push element x onto stack. 
 * @param {number} x
 * @return {void}
 */
MyStack.prototype.push = function(x) {
    let qu1=this.qu1; //保证qu1中只有一个元素
    let qu2=this.qu2;
    qu1.push(x);
    while(qu1.length>1){
        let tem = qu1.shift();
        qu2.push(tem);
    }

};

/**
 * Removes the element on top of the stack and returns that element.
 * @return {number}
 */
MyStack.prototype.pop = function() {
    let qu1=this.qu1; //保证qu1中只有一个元素
    let qu2=this.qu2;
    if(qu1.length==0)return null;
    let ret= qu1.shift();
    while(qu2.length>0){
        qu1.push(qu2.shift());
    }
    while(qu1.length>1){
        let tem = qu1.shift();
        qu2.push(tem);
    }
    return ret;

};

/**
 * Get the top element.
 * @return {number}
 */
MyStack.prototype.top = function() {
    return this.qu1[0];
};

/**
 * Returns whether the stack is empty.
 * @return {boolean}
 */
MyStack.prototype.empty = function() {
    return this.qu1.length===0;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * var obj = new MyStack()
 * obj.push(x)
 * var param_2 = obj.pop()
 * var param_3 = obj.top()
 * var param_4 = obj.empty()
 */
```