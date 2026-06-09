JS解法：
1、先判断x是否满足条件，不满足直接置为0节省运算成本。
2、将满足条件的数字X的绝对值，转为字符串y,开始进行颠倒运算，思路为JS的字符串下标进行取值，用+=的方式拼接到新的字符串len上去，
3、输出经过判断的len的值：绝对值是否大于2**31，是否小于0，小于0拼接个减号上去，再转换为数字
```
var reverse = function(x) {
    Math.abs(x)>(2**31-1)?x=0:x;
    if(x == 0) return 0
    let y = Math.abs(x).toString(),len='';
    for(var i =0;i<y.length;i++){len += y[y.length-i-1]}
    return parseInt(Math.abs(len)>(2**31-1)?len=0:(x<0?-len:len));
};
```

PS：当然我这里对数值的判断简单了点Math.abs(x)>(2**31-1)，是否有极限情况没有考虑到？先发布题解再一试～