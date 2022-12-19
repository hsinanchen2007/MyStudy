### 解题思路
字符串拼接，只改变一个获得最大，只需要检索字符串第一次出现6的地方，把6变成9即为最大。

### 代码

```javascript
/**
 * @param {number} num
 * @return {number}
 */
var maximum69Number  = function(num) {
    var str = num.toString();
    var index = str.indexOf("6");
    if(index == -1){
        return num
    }
    //console.log(index)
    return str.substr(0,index)+"9"+str.substring((index+1),str.length) 
};
```