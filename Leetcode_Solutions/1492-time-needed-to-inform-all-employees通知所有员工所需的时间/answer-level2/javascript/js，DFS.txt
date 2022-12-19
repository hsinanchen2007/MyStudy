```
var numOfMinutes = function(n, headID, manager, informTime) {
    if(n===1)return informTime[0];

    // 转换manager数组为，每个领导有哪些下属的形式。形成父节点和子节点的更清晰的对应关系
    let hash = {};
    for(let i = 0; i < manager.length; i++){
        if(!hash[manager[i]])hash[manager[i]] = [];
        hash[manager[i]].push(i);
    }

    let max = 0;
    let dfs = (leadId, curTime) => {
        let next = hash[leadId];
        if(!next){
            max = Math.max(max, curTime);
            return;
        }
        for(let k = 0; k < next.length; k++){
            dfs(next[k], curTime + informTime[next[k]])
        }
    };
    dfs(headID, informTime[headID])
    return max;
};
```
前端算法库：https://github.com/cunzaizhuyi/js-leetcode  
这里记录了我刷过的近500道LeetCode的题解，
希望对前端同行找工作面试、修炼算法内功有帮助。
前端算法交流群：621067993