```
var combinationSum = function (candidates, target) {
    var resultList = [];
    var combin = function (value, path) {
        if (value === 0) return resultList.push(path.slice());

        if (value < 0) return;

        for (var i = 0; i < candidates.length; i++) {
            if (path.length === 0 || (path.length > 0 && path[path.length - 1] >= candidates[i])) {
                var minus = value - candidates[i];
                path.push(candidates[i]);
                combin(minus, path);
                path.pop(candidates[i]);
            }
        }
    };

    combin(target, []);
    return resultList;
};
```
