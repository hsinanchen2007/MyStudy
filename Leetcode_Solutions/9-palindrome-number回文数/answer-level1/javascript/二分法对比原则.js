### 解题思路
回文，即以位于正中间的数字为中点进行分割，两边的数据完全对称。
所以，如果设定一个循环，从整数第一位下标开始，第一位与最后一位对比，第二位与倒数第二位对比，回文两边的数字会全部相等，循环次数最大值为Math.floor(x.length/2), 而如果不一致，则判断非回文，即刻退出循环。

另外，负数肯定不是回文，所以单独拎出来做一个判断。

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