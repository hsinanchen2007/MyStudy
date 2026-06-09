### 解题思路
关键：循环次数最大值为Math.floor(x.length/2), 而如果不一致，则判断非回文

### 代码

```javascript
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    if(x<0) return false;
    
    let flag = true;
    x = x.toString()

    for(let i=0, len=x.length; i<len/2; i++){
        if(x[i] !== x[len-1-i]){
            flag = false;
            break
        }
    }
    return flag
};
```