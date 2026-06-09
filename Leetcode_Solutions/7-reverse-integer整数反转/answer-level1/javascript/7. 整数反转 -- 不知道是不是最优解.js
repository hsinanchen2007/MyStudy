### 执行结果
![image.png](https://pic.leetcode-cn.com/099522405ffd9fc535fecbee7f6f5582bfa27b03c18c0c1a5f807b1ff3d5d4b6-image.png)

### 解题思路
先判断正负数，将负数标记出来，然后将数值全都转换为整数，因为正数好操作。
然后对整数不断取余，按取余顺序入栈，这样栈里的顺序就是正好倒过来的了。
因为我最后用的是 + 来将字符串转换为数字类型，所以如果转换后第一位是 0 ，则会自动消除。

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    let arr = []
    let tmp = 0;
    if (x < 0) {
        arr.push("-")
    }
    x = Math.abs(x)
    while(x) {
        arr.push(x % 10)
        x = Math.floor(x / 10)
    }
    
    arr = arr.join("")
    arr = +arr
     if (arr > (2**31 -1) || arr < -(2**31)) {
        return 0;
    }
    return arr
};
```