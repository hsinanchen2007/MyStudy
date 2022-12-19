### 解题思路
我吐了，我以为我过不了了
后来检查代码发现我调试的时候写的console.log忘了删了，删了就过了，不过时间还是很糟糕hhhhh

其实map更好用，我就是想用数组写着玩hhh
两个数组，一个数组存key 一个数组存value
每次操作都需要对两个数组都进行操作，所以时间上很糟糕

有个坑，挪Key的时候跟着去挪value，一定要用key的下标，我zz了用了indexof（value），结果数组里有重复的value值= =  
为了发现这个错误我写了几十行测试样例= =
查到之后只能骂自己傻哔.....
### 代码

```javascript
/**
 * @param {number} capacity
 */
var tmp;
var index;

var LRUCache = function(capacity) {
    this.capacity=capacity;
    this.keys=[];
    this.values=[];

};

/** 
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function(key) {
    if (this.keys.indexOf(key)!==-1){
        tmp=this.values[this.keys.indexOf(key)]
        index=this.keys.indexOf(key)
        this.keys.splice(this.keys.indexOf(key),1)
        this.values.splice(index,1)
        this.keys.unshift(key)
        this.values.unshift(tmp)
        return tmp
    }
    else return -1
};

/** 
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function(key, value) {
    if (this.keys.indexOf(key)!==-1){
        this.values[this.keys.indexOf(key)]=value
        tmp=this.values[this.keys.indexOf(key)]
        index=this.keys.indexOf(key)
        this.keys.splice(this.keys.indexOf(key),1)
        this.values.splice(index,1)
        this.keys.unshift(key)
        this.values.unshift(tmp)
        return

    }
    if (this.keys.length<this.capacity){
        this.keys.unshift(key)
        this.values.unshift(value)
    }
    else{
        this.keys.pop()
        this.values.pop()
        this.keys.unshift(key)
        this.values.unshift(value)
    }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * var obj = new LRUCache(capacity)
 * var param_1 = obj.get(key)
 * obj.put(key,value)
 */
```