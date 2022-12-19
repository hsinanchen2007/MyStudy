### 解题思路

进行一次排序，可以减少回溯中for循环的次数
### 代码

```javascript
/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
    let rs = [], stack = [];
    candidates.sort((n1, n2)=> n1-n2);
    (function sniffing(target, stack, start){
        if(target===0){
            rs.push([...stack]);
        }
        for(let i = start; candidates[i]<=target; i++){
            stack.push(candidates[i]);
            sniffing(target-candidates[i], stack, i);
        }
        stack.pop();
    })(target, stack, 0);
    return rs;
};
```