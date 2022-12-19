```
var maxDepthAfterSplit = function(seq) {
    let deps = [0,0];
    let maxDep = 0;
    const rtn = [];
    for (let char of seq) {
        let val;
        if (char === '(') {
            // 寻找较小的入栈
            val = deps[0] > deps[1] ? 1 : 0;
            maxDep = Math.max(maxDep, ++deps[val])
        } else {
            // 寻找较大的出栈
            val = deps[0] > deps[1] ? 0 : 1;
            deps[val]--;
        }
        rtn.push(val);
    }
    return rtn;
};
```
