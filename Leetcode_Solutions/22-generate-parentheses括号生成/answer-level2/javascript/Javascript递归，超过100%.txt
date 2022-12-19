![1.jpg](https://pic.leetcode-cn.com/4d398dbf62269b1950752fa18a6b52a5b059925767d4c0ecd24db0f4aa7ab219-1.jpg)

先给代码：
``` javascript
var generateParenthesis = function(n) {
    var res = new Set();
    //n代表'('的剩余数量，m代表')'的可使用数量，s表示已选择的字符串
    function dfs(n, m, s){
        if(n == 0){
            s += ')'.repeat(m);
            res.add(s);
            return;
        }
        m+=1;
        var temp = '('
        for(var i = 0;i <= m;i++){
            dfs(n-1, m-i, s+temp);
            temp += ')'
        }
    }
    if(n != 0) dfs(n, 0, '');
    return Array.from(res);
};
```

这道题类似于abc字符串生成全排列，但是它有一个限制，所有生成的字符串的字串'('出现的次数必须大于等于')'出现的次数，否则它是不合法的字符串，比如'())('。所以在生成字符串的时候保证所有字串都满足上述条件即可。