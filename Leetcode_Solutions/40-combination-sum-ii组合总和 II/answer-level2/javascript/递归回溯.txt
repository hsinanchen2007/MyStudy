### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum2 = function(candidates, target) {
    let result = []
    candidates.sort( (a,b) => a-b)
    // 记录组合
    let path = []
    trace(candidates, 0, target, path, result)
    return result
   
   

};
function trace(candidates, start, target, path, result){
    if(start >= candidates.length || target < 0) return 
    path.push(candidates[start])
    
    target = target - candidates[start]
   
    if(target == 0 && !isContain(result, path)) {
        // 这里有一个坑，找了半天才找出来
        // 这里不能直接 result.push(path), 因为全局共用一个path路径，直接push，push的是数组引用，后续会一直改变，所以一定 push 数组副本
        result.push(path.slice())
    }
    trace(candidates, start+1, target, path, result)
    target = target + candidates[start]
    path.pop()
    trace(candidates, start+1, target, path, result)
}
function isContain(arr1, arr2){
    return arr1.some((arr)=>{
        return JSON.stringify(arr)==JSON.stringify(arr2)
    
    })
}
```