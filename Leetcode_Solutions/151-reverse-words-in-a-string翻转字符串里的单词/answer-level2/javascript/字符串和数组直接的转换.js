### 解题思路
1. 根据空格符把字符串转换为数组，并把空格符元素过滤
2. 使用reverse函数翻转数组元素
3. 使用join函数把数组转换为字符串

### 代码

```javascript
/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
    // 转换为数组
    // 解法一
    // let arr_1 = s.split(' ').filter(function(val){ 
    //     return val; 
    // });
    // let str_new = '';
    // for(let i = 0; i < arr_1.length; i++){
    //     let word = (i == arr_1.length-1) ? arr_1[0] : (arr_1[arr_1.length - i -1] + ' ');
    //     str_new = (str_new + word) ;
    // }
    // return str_new;
    // 解法二
    let arr_1 = s.split(' ').filter(function(val){
        return val;
    }).reverse().join(' ');
    return arr_1;
};
```