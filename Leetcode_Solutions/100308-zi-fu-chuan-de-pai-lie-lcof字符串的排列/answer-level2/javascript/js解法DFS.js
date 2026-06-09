```
var permutation = function(s) {
    let vis = [];
    let res = [];
    let dfs = (step, curP) => {
        if (step === s.length){
            if(res.indexOf(curP)===-1){
                res.push(curP);
            }
            return;
        }
        for (let i = 0; i < s.length; i++){
            if (vis[i] === true) continue;
            vis[i] = true;
            dfs(step + 1, curP + s[i]);
            vis[i] = false;
        }
    }
    dfs(0, '');
    return res;
};
```

前端算法库：https://github.com/cunzaizhuyi/js-leetcode  
这里记录了我刷过的近500道LeetCode的题解，
希望对前端同行找工作面试、修炼算法内功有帮助。
前端算法交流群：621067993