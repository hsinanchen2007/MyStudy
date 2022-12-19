### 解题思路
先转化为3进制字符串，只有第一位是1，其余为均为0

### 代码

```javascript
/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfThree = function(n) {
    var str=n.toString(3);
    var count_0=0,count_1=0;
    for(var i=0;i<str.length;i++){
        if(str[i]=='1'){
            count_0++;
        }
        if(str[i]=='0'){
            count_1++;
        }
    }
    if(str[0]=='1'&& count_0==1 && count_1==(str.length-1)){
        return true;
    }
    return false;
};
```