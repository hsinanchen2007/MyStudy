### 解题思路
bfs

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsets = function(nums) {
    let queue = [...nums]
    let ans = [[]]
    while(queue.length) {
        let cur = queue.pop()
        let arr = [[cur]]
        
        for(let i in queue) {
            let tmp = arr.map(ele => ele.concat([queue[i]]) )
            arr.push(...tmp)
        }
        ans.push(...arr)
    }
    // console.log(ans)
    return ans
};
```