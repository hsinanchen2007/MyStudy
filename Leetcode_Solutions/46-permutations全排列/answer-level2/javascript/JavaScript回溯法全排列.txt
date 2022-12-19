### 解题思路
回溯法解决经典全排列问题

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permute = function(nums) {
    let result = [];
    let trackback = function(track){
        if(track.length===nums.length){
            result.push(track.slice(0));
            return;
        }
        for(let i=0;i<nums.length;i++){
            if(track.indexOf(nums[i])>-1) continue;
            trackback(track.concat([nums[i]]));
        }
    }
    trackback([]);
    return result;
};
```