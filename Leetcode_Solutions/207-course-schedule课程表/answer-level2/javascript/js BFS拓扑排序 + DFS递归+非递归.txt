js 拓扑排序
```js
var canFinish = function(numCourses, prerequisites) {
    const indegree = new Array(numCourses).fill(0);
    const record = {};
    const len = prerequisites.length;
    for(let i = 0; i < len; i++) {
        if(!record[prerequisites[i][0]])
            record[prerequisites[i][0]] = [];
        record[prerequisites[i][0]].push(prerequisites[i][1]);
        indegree[prerequisites[i][1]] = indegree[prerequisites[i][1]] ? indegree[prerequisites[i][1]] + 1 : 1;
    }
    const queue = [];
    for(let i = 0; i < numCourses; i++) {
        if(indegree[i] === 0) queue.push(i);
    }
    const res = [];
    while(queue.length) {
        const front = queue.shift();
        if(front === undefined) continue;
        res.push(front);
        if(!record[front]) continue;
        let i = record[front] ? record[front].length : 0;
        while(i--) {
            const child = record[front][i];
            indegree[child]--;
            if(!indegree[child]) queue.push(child);
        }
    }
    return res.length === numCourses;
};
```

js DFS递归
```js
/**
 * @param {number} numCourses
 * @param {number[][]} prerequisites
 * @return {boolean}
 */
var canFinish = function(numCourses, prerequisites) {
    const record = {};
    prerequisites.forEach(([pre, next]) => {
        if(!record[pre]) record[pre] = [];
        record[pre].push(next); // 构建有向图
    })
    let flag = []; // 标志位表示该课程是否被遍历 -1: 上一个DFS被遍历；0: 没有被遍历；1:本轮已被遍历
    for(let i = 0; i < numCourses; i++) {
        if(isCircle(i)) return false;
    }
    function isCircle(course) {
        if(flag[course] === 1) return true;
        if(flag[course] === -1) return false;
        flag[course] = 1;
        if(record[course] && 
            record[course].some(child => isCircle(child)))
            return true;
        flag[course] = -1;
        return false;
    }
    return true;
};
```
js DFS非递归
```js
function canFinish(N, arr) {
    const indegree = new Array(N).fill(0);
    const record = {};
    arr.forEach(([pre, next]) => {
        if(!record[pre]) record[pre] = [];
        record[pre].push(next); // 构建有向图
        indegree[next]++; // 入度计算
    })
    const stack = indegree.reduce((t, i, index) => {
        !i && t.push(index);
        return t;
    }, []); // 寻找起点
    const res = [];
    const flag = [];
    while(stack.length) {
        const front = stack.pop();
        res.push(front);
        flag[front] = 1;
        const nexts = record[front];
        if(nexts) {
            const len = nexts.length;
            for(let j = 0; j < len; j++) {
                if(flag[nexts[j]] === 1) return false;
                if(flag[nexts[j]] === -1) continue;
                if(!--indegree[nexts[j]]) stack.push(nexts[j]);
            }
        }
        flag[front] = -1;
    }
    return res.length === N;
}
```


