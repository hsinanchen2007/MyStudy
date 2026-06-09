
### 代码

```javascript
/**
 * @param {number} n
 * @param {number} k
 * @return {number[][]}
 */
var combine = function(n, k) {
     let res = [],tmpPath = []
    let backtrack = (tmpPath,start) => {
      if(tmpPath.length === k){
        res.push(tmpPath)
        return
      }
      for(let i = start;i<=n;i++){
        tmpPath.push(i)
        backtrack(tmpPath.slice(),i+1)
        tmpPath.pop()
      }
    }
    backtrack(tmpPath,1)
    return res
};
```