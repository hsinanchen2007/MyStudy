### 解题思路
1.转换字符串
2.转成字符串数组
3.反转字符串数组
4.组合字符串
5.取整去零
5.判断边界
6.判断是否添加符号

### 代码

```javascript
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x){
        var str = parseInt(x.toString().split("").reverse().join(""));
        if(str > Math.pow(2, 31) - 1 || str < -Math.pow(2, 31)){
            return 0;
        }
        return x < 0 ? -str:str;
    }
```