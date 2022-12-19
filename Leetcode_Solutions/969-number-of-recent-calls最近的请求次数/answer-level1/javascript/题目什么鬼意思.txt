### 解题思路
很惭愧,在下阅读理解是体育老师教的.

说是有个构造函数, 也就是它说的类, 其中有个方法ping, 它会传入个参数时间 t 

在这个时间 的 过去 3 秒 内, 有个喇叭ping个不停, 求在这个3秒内这个喇叭 ping了多少下

所以现在构造函数里先定义个 数组 用来 存放 ping时候 的 时间, 每ping一下 就存ping的时间, 超过3秒的 就把超过的删了, 

题目说返回ping的数 , 那咱就返回 这个数组的长度就行了, 毕竟每ping一下 都往数组里存了个元素, 他的长度就是ping的数.

看着题目就憋屈, 读不懂, 在下太难了

### 代码

```javascript
var RecentCounter = function() {
    this.val = []
};

/** 
 * @param {number} t
 * @return {number}
 */
RecentCounter.prototype.ping = function(t) {
    this.val.push(t)
    while( this.val[0] < t-3000){
      this.val.shift()
    }
    return this.val.length
};

/** 
 * Your RecentCounter object will be instantiated and called as such:
 * var obj = new RecentCounter()
 * var param_1 = obj.ping(t)
 */
```