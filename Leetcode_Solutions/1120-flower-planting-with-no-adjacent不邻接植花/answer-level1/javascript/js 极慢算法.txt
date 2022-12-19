极慢算法
```
var gardenNoAdj = function(N, paths) {
    const record = {};
    paths.forEach(path => {
        if(!record[path[0]]) record[path[0]] = [path[1]];
        else record[path[0]].push(path[1]);
        if(!record[path[1]]) record[path[1]] = [path[0]];
        else record[path[1]].push(path[0]);
    })
    const res = [];
    let colors;
    for(let i = 1; i <= N; i++) {
        colors = [1,2,3,4];
        record[i] && record[i].forEach(connectPath => {
            const selectedColorIndex = colors.indexOf(res[connectPath]);
            selectedColorIndex >= 0 && colors.splice(selectedColorIndex, 1);
        })
        res[i] = colors[0];
    }
    return res.slice(1);
};
```
