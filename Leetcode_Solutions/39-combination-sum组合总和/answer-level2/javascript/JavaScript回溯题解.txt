### 解题思路
典型的回溯

### 代码

```javascript
/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
    let result=[];
    let trackback = function(idx,track){
        let sum = track.length!==0?track.reduce((x,y)=>x+y):0;
        if(sum>=target){
            sum===target && result.push(track.slice(0));
            return;
        }
        for(let i=idx;i<candidates.length;i++){           
            trackback(i,track.concat([candidates[i]]));
        }
    }
    trackback(0,[]);
    return result;
}
```