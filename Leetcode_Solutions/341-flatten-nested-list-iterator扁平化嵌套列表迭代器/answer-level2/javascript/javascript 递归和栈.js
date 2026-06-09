
# 递归

![image.png](https://pic.leetcode-cn.com/09efe5f5fd61e28e4bdc6c000e3815a1be490149f74dbbdcb7323f03f42c0e32-image.png)


``` 
var NestedIterator = function(nestedList) {
    this.list = [];
    this.resetList(nestedList);
}; 
NestedIterator.prototype.resetList = function(arr) {
    for (let i = 0; i < arr.length; i++) {
        if (arr[i].isInteger())
            this.list.push(arr[i].getInteger())
        else
            this.resetList(arr[i].getList())
    }
}; 
NestedIterator.prototype.hasNext = function() {
    return this.list.length > 0;
}; 
NestedIterator.prototype.next = function() {
    return this.list.shift();
};
```



# 使用栈 
![image.png](https://pic.leetcode-cn.com/5b01d838953e566ea8614198d62690bc37862c602909804ec6380253b8a6162f-image.png)


``` 
var NestedIterator = function(nestedList) {
    this.num = null;
    this.flag = false;
    this.stack = [];
    this.stack.push(nestedList);
}; 
NestedIterator.prototype.next = function() {
    this.flag = false;
    return this.num;
};
NestedIterator.prototype.hasNext = function() {
    if (!this.stack.length)
        return false;
    while (this.stack.length && !this.flag) {
        let temp = this.stack[this.stack.length - 1];
        if (temp.length) {
            let tt = temp.shift()
            if (tt.isInteger()) {
                this.num = tt.getInteger();
                this.flag = true;
            } else
                this.stack.push(tt.getList());
        } else {
            this.stack.pop();
        }
    }
    return this.flag;
};
```


