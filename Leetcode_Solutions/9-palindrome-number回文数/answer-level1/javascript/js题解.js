
### 代码
方法一：

```javascript
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    if(x >= 0){
        let result = parseInt(x.toString().split("").reverse().join(""));
        return (result == x)? true : false;
    }else{
        return false;
    }
};
```
**结果**
执行用时：232ms, 内存消耗 45.7MB

方法二：(参考官方题解)

```javascript
if(x < 0 || x % 10 == 0 && x != 0){
        return false;
} else {
    let newNumber = 0;
    while(x > newNumber){
        newNumber = newNumber * 10 + x % 10;
        x = parseInt(x/10);
    }
    return x == newNumber || x == parseInt(newNumber/10);
}
```
**结果**
 执行用时：176ms，击败99.79%
 内存消耗：44.7MB，击败 93.17%