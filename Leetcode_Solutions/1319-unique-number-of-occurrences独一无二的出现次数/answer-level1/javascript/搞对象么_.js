### 解题思路

**创建个对象,把 传入数组每一项当做 属性, 数组中每重复一项, 对象的值就加1**

如:[1,2,2,1,1,3]  =>  {1: 3, 2: 2, 3: 1}

**再创建个数组 存放 对象的值,** 

得到数组 [3, 2, 1]

**判断去重后的数组 是否 与未去重的长度相等 ,**

去重后 [3, 2, 1]

**就能知道 每个数的出现次数都是独一无二的**

[3, 2, 1].length === [3, 2, 1].length , 所以返回true

![image.png](https://pic.leetcode-cn.com/229835ede220e6868814715758508288d221a407bb8ed2b37e478a701581200f-image.png)

### 代码

```javascript
/**
 * @param {number[]} arr
 * @return {boolean}
 */
var uniqueOccurrences = function(arr) {
    let obj = {}
    arr.forEach(item=>{
      obj[item] = obj[item] ? ++obj[item] : 1
    })
    let list = []
    for(let prop in obj){
      list.push(obj[prop])
    }
    return [...new Set(list)].length === list.length
};
```


用对象的高阶函数好像慢点 [Object.values()](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/Object/values)

![image.png](https://pic.leetcode-cn.com/6c4cd36274fc7fc10934016a03ef7b15bd4cfa3de248331203f6319744f93fd4-image.png)

```
var uniqueOccurrences = function(arr) {
    let obj = {}
    arr.forEach(item=>{
      obj[item] = obj[item] ? ++obj[item] : 1
    })
    let list = Object.values(obj)
    return [...new Set(list)].length === list.length
};
```




Object.values()方法返回一个给定对象自身的所有可枚举属性值的数组，
值的顺序与使用for...in循环的顺序相同 
( 区别在于 for-in 循环枚举原型链中的属性 )。

ps:

MDN 上面有 手写的 Object.values()

```js
if (!Object.values) Object.values = function(obj) {
    if (obj !== Object(obj))
        throw new TypeError('Object.values called on a non-object');
    var val=[],key;
    for (key in obj) {
        if (Object.prototype.hasOwnProperty.call(obj,key)) {
            val.push(obj[key]);
        }
    }
    return val;
}
```
