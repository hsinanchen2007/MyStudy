### 方法一
 判断拥有的每一个石头，是否属于宝石，利用ES7的includes方法和es6的filter

### 代码

```javascript
/**
 * @param {string} J
 * @param {string} S
 * @return {number}
 */
var numJewelsInStones = function(J, S) {
    let result = null;
    let array_S = S.split("");
    result = array_S.filter(key =>{
        return J.includes(key)
    }).length
    console.log(result)
    return result
};
```

### 方法二
双循环遍历拥有的每一个石头，是否属于宝石

### 代码

```javascript
/**
 * @param {string} J
 * @param {string} S
 * @return {number}
 */
var numJewelsInStones = function(J, S) {
    let result = null;
    let array_S = S.split("");
    let array_J = J.split("");
    array_S.forEach(item =>{
        array_J.forEach(key =>{
            if(item == key){
                result ++
            }
        })
    })
    console.log(result)
    return result
};
```