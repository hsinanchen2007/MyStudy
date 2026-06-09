JS 拓扑排序
```
var findOrder = function(numCourses, prerequisites) {
    const record = {};
    const inDegree = new Array(numCourses).fill(0);
    prerequisites.forEach(([pre, next]) => {
        if(!record[pre]) record[pre] = [];
        record[pre].push(next);
        inDegree[next]++;
    })
    const queue = inDegree.reduce((t, i, index) => {
        if(!i) t.push(index);
        return t;
    }, []);
    let i = queue.length;
    const res = [];
    while(i) {
        while(i--) {
            const front = queue.shift();
            res.push(front);
            record[front] && record[front].forEach(child => {
                if(!--inDegree[child]) queue.push(child);
            }) 
        }
        i = queue.length;
    }
    return res.length === numCourses ? res.reverse() : [];
};
```
