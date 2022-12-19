### 解题思路
首先判断正负，负数一定是false。正数再运用反转数字的方法将数字反转，由于在反转过程中会将原始数字进行改变，所以先用一个变量将其存储起来。最后将反转后的数字与原始数字进行比较是否相同，返回结果。

### 代码

```javascript
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    var origin = x;
    var y = 0;
    if(x >= 0){
        while(x != 0){
            y = y*10 + x%10;
            x = ~~(x/10);
        }
        if(y == origin){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
   

    
};
```