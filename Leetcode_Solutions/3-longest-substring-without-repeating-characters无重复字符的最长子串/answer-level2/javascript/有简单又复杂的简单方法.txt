### 解题思路
用滑动窗口的方法来解题
1.定义一个窗口(Array)win,最大长度long
2.遍历(String)s每一个字符
3.条件判断: 因为重复的字符可能出现在数组前面，中间，后面
所以只要用win.indexOf(s[i])>0 判断原组是否存在s[i],如果
存在，就用splice分割出不包含s[i]的后半部分数组，并和新的
s[i]相合并，形成新数组
4.长度在win.push后面添加这条语句就行了，节省了很多内存
long = win.length > long ? win.length : long;
### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    if(s === ''){
        return 0
    }
    let win = []
    let long = 0
    for(let i = 0; i < s.length; i++){
        if(win.length > 0 && win.indexOf(s[i]) >= 0 ){
            // 先把重复的元素添加进去
            win.push(s[i])
            // 切割掉数组中第一个重复元素之前的部分
            // 比如[1,2,3,4,5,6,7,8,9,5]
            // 切割之后就变成了[6,7,8,9,5]
            win = win.splice(win.indexOf(s[i]) + 1,win.length-1)
            long = win.length > long ? win.length : long;
        }else{
            win.push(s[i])
            long = win.length > long ? win.length : long;
        }
    }
    return long
};
```