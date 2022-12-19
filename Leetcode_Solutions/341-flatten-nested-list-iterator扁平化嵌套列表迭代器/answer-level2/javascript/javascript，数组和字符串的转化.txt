### 解题思路
把多维数组通过join或者toString转化为字符串，再用split转为一维数组。

重写了NestedInteger的toString方法，让NestedInteger[]可以和普通数组一样可以转为字符串

### 代码

```javascript
NestedInteger.prototype.toString = function() {
    if (this.isInteger()) {
        return this.getInteger()+'';
    } else {
        return this.getList().toString();
    }
}
var NestedIterator = function(nestedList) {
    this.list = nestedList.toString().split(",").filter((val)=>{return val != ""});
};
NestedIterator.prototype.hasNext = function() {
    return this.list.length > 0;
}; 
NestedIterator.prototype.next = function() {
    return this.list.shift();
};
```