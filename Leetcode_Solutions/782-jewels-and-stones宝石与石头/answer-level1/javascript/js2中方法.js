### 解题思路
此处撰写解题思路
方法一：暴力双循环，将子串转数组，遍历拥有的石头，是否属于宝石
### 代码

```javascript
var numJewelsInStones = function(J, S) {
    let result = null;
    let array_J = J.split("");
    let array_S = S.split("");
    array_S.forEach(item =>{
        array_J.forEach(key =>{
            if(item == key){
                result++
            }
        })
    })
    console.log(result)
    return result
};
```
### 解题思路
此处撰写解题思路
方法二：es6写法，总体思路其实不变，换汤不换药
### 代码

```javascript
var numJewelsInStones = function(J, S) {
    let result = null;
    let array_S = S.split("");
    result = array_S.filter(key =>{
        return J.includes(key).length
    })
    console.log(result)
    return result
};
```