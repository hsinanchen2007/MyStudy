
### 代码

```javascript
/**
 * @param {string} s
 * @return {string[]}
 */
var permutation = function(s) {
    this.res = [];
    this.s = s.split("").sort().join("");
    this.checked = new Array().fill(0);
    bfs(0, "");
    return res;
};

var bfs = function(n, item){
    if(n == this.s.length){
        this.res.push(item);
        return;
    }
    for(var i = 0; i < this.s.length; i++){
        if(this.checked[i] || i > 0 && this.s[i] == this.s[i-1] && !this.checked[i-1]) 
            continue;
        this.checked[i] = 1;
        bfs(n + 1, item + this.s[i]);
        this.checked[i] = 0;
    }
}
```