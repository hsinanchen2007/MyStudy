### 解题思路
深度优先，剪枝。
结果去重的方法是将结果数组转换成 字符串，然后看是否含有这个字符串，速度比较慢，但是很简单，因为本来就进行了剪枝，所以重复结果并不多，还是具有一定可行性的，用时大概90ms左右。

### 代码

```javascript
/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum2 = function(candidates, target) {
    candidates.sort((a, b) => a-b);
    let result = [];
    let visited = [];
    let resultByStr = [];
    function DFS(sum, item, index){
        for(let i = index; i < candidates.length; i++){
            if(!visited[i]){
                visited[i] = true; 
                if(candidates[i] < item[item.length-1]){
                    visited[i] = false;
                    continue;
                }
                let now = candidates[i] + sum;
                if(now == target){
                    item.push(candidates[i]);
                    let [...newItem] = item;
                    let str = newItem.join("")
                    if(resultByStr.indexOf(str) == -1){
                        result.push(newItem)
                        resultByStr.push(str);
                    }
                    item.pop();
                    visited[i] = false;
                    return;
                }
                else if(now < target){
                    item.push(candidates[i]);
                    DFS(now, item,index+1);
                    item.pop();
                    visited[i] = false;
                }else{
                    visited[i] = false;
                    return;
                }
            }
        }
    }
    for(let i = 0; i < candidates.length; i++){
        if(candidates[i] != candidates[i-1] && candidates[i] <= target){
            if(candidates[i] == target){
                result.push([candidates[i]]);
                continue;
            }
            visited[i] = true;
            DFS(candidates[i], [candidates[i]], i);
            visited[i] = false;
        }
    }
    return result;
};
```