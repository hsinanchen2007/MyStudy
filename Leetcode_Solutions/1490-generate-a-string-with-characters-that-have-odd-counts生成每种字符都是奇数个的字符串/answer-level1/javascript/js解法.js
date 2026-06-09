```
var generateTheString = function(n) {
    if(n===0)return '';
    if(n===1)return 'a';
    let res = '';
    let to = 'abcdefghijklmnopqrstuvwxyz';
    if (n % 2 === 0){
        res += 'b';
        for(let i = 1; i <= n-1; i++){
            res += 'a';
        }
    }else{
        for(let i = 1; i <= n; i++){
            res += 'a';
        }
    }
    return res;
};
```

前端算法库：https://github.com/cunzaizhuyi/js-leetcode  
这里记录了我刷过的近500道LeetCode的题解，
希望对前端同行找工作面试、修炼算法内功有帮助。
前端算法交流群：621067993
