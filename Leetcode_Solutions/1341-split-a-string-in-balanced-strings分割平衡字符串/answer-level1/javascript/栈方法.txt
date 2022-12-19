### 解题思路
可以用栈方法来解, 首先得把它转成数组,我们得遍历它,然后判断 每一项 等于 L 就加1 R就减1 等加和减都抵消了,就能截得一项了,以此类推继续执行下去,直到遍历完这个数组, 要是都抵消不了 它也会返回0, 也符合题意

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var balancedStringSplit = function(s) {
    let list = s.split('')
    let num = 0
    let stack = 0
    let len = list.length
    for(var i = 0;i<len;i++){
      if(list[i] === 'L'){
        stack++
      } else {
        stack--
      }
      if(stack === 0){
        num++ 
      }
    }
    return num
};
```