1. 利用递归解法
2. 空字符串添加（ 或者 ），长度等于2n则push到树组中
3. 如果left 小于 n，就加一个 （
4. 如果right小于left，就加一个 ）


```
var generateParenthesis = function(n) {
    let res = [];
    const fn = (cur,left,right) => {
        if(cur.length === 2*n) {
            res.push(cur)
        }
        if(left < n) {
            fn(cur+"(",left+1,right)
        }
        if(right<left) {
            fn(cur+')',left,right+1)
        }
    }
    fn('',0,0);
    return res;
};
```



