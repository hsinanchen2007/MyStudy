### 解题思路
此处撰写解题思路

### 代码

```javascript
var CQueue = function() {
    s = [], s2 = [] // 双栈 其中s2为辅助栈
};

/** 
 * @param {number} value
 * @return {void}
 */
CQueue.prototype.appendTail = function(value) {
    s.push(value)
};

/**
 * @return {number}
 */
CQueue.prototype.deleteHead = function() {

    
    if (!s.length) return -1
    // return s.shift() 普通解法... 

    // 双栈（算法青年）解法 ... 
    while (s.length) 
        s2.push(s.pop())
    
    let ret = s2.pop()
    while (s2.length)
        s.push(s2.pop())

    return ret
};

/** 
 * Your CQueue object will be instantiated and called as such:
 * var obj = new CQueue()
 * obj.appendTail(value)
 * var param_2 = obj.deleteHead()
 */
```