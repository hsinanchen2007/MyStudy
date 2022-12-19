### 解题思路
1. 根据空格符把字符串转换为数组，并过滤空格符元素
2. 循环数组，把数组从末到头以此拼接到字符串变量中
3. 返回字符串变量

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    // 转换为数组
    let arr_1 = s.split(' ').filter(function(val){ 
        return val; 
    });
    let str_new = '';
    for(let i = 0; i < arr_1.length; i++){
        let word = (i == arr_1.length-1) ? arr_1[0] : (arr_1[arr_1.length - i -1] + ' ');
        str_new = (str_new + word) ;
    }
    return str_new;
};
```