先用暴力法写了一遍，1600+ms，我的天哪。。。

再仔细想想，利用后缀构建一个树形结构应该大大加快查询速度，所以先来写基础数据结构：
```javascript
function Node (char) {
    this.char = char;
    this.children = [];
}
Node.prototype.insert = function(strArray) {
    let last = strArray.pop();

    let mid = false, midNode = null;
    for(let node of this.children) {
        if(node.char === last) {
            mid = true;
            midNode = node;
            break;
        }
    }
    if(mid === false) {
        let newNode = new Node(last);
        if(strArray.length > 0) {
            newNode.insert(strArray);
        }
        this.children.push(newNode);
        return false;
    } else {
        if(strArray.length === 0) {
            return true;
        } else {
            return midNode.insert(strArray);
        }
    }
}
```
简单起见，就只写了一个实例方法insert，集插入和查询为一体，虽然从设计来说有点违背单一职责原则，但是使用起来蛮方便，实用主义一下。
接下来就是使用它了，就很简单了：
```js
/**
 * @param {string[]} words
 * @return {number}
 */
var minimumLengthEncoding = function(words) {
    words.sort((a,b)=>{
        return b.length - a.length;
    })
    let tree = new Node();
    let ret = [];
    for(let item of words) {
        if(!tree.insert(item.split(''))) {
            ret.push(item);
        }
    }
    let sum = 0;
    for(let item of ret){
        sum += item.length;
    }
    return sum += ret.length;
};
```
