循环对path /../ ./ //解析，其余情况不做处理
```js
var simplifyPath = function(path) {
    while(true){
        while(/\/\//.test(path)) path = path.replace('//', '/');
        while(/(^|\/)\.(\/|$)/.test(path)) path = path.replace(/(^|\/)\.(\/|$)/, '/');
        while(/(^|\/)\.\.(\/|$)/.test(path)){
            path = path.replace(/(\w+)\/\.\./, '');
            if(path.indexOf('/..') === 0) path = path.replace(/\/\.\./, '/');
            if(/\/\//.test(path)) path = path.replace('//', '/');
            if(/(^|\/)\.(\/|$)/.test(path)) path = path.replace(/(^|\/)\.(\/|$)/, '/');
        }
        if(!/(^|\/)\.(\/|$)/.test(path) && !/(^|\/)\.\.(\/|$)/.test(path) && !/\/\//.test(path)) break;
    }
    path = path.replace(/\/$/, '');
    if(path[0] !== '/') path = '/' + path;
    return path;
};
```