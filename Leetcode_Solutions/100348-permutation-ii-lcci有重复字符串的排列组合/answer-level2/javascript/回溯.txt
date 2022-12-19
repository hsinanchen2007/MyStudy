### 解题思路
![3CE5A021-B18D-47B3-9282-AD6145B9EDBB.png](https://pic.leetcode-cn.com/93ffcdedbb4c6b3a6f7d388b39f733f1e8d943243b0e1107e44c149a51957e74-3CE5A021-B18D-47B3-9282-AD6145B9EDBB.png)
### 代码


```javascript
/**
 * @param {string} S
 * @return {string[]}
 */
var permutation = function(S) {
    let res = []
    backtrack('', S.split('').sort().join(''))
    function backtrack(path, S) {
        if (S === '') {
            return res.push(path)
        }
        for (let i = 0; i < S.length; i++) {
            if (i>0 && S[i-1]=== S[i]) continue
            path+=(S[i])
            backtrack(path, S.slice(0, i).concat(S.slice(i+1)))
            path = path.slice(0,path.length-1)
        }
        
    }
    return res
};
```