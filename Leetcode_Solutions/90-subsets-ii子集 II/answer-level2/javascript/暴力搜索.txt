### 解题思路
先排个序(因为不能包含重复子集))，然后暴力枚举出所有子集后在去重就好

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */

let vis, ans, ext
var subsetsWithDup = function(nums) {
    vis = ext = {}
    ans = [[]]
    dfs(nums.sort((a,b) => a-b), [], 0)
    return ans
};

function dfs(arr, cur, lv) {
    for(let i = lv; i < arr.length; i++) {
        cur.push(arr[i])
        update(cur)
        dfs(arr, cur, i + 1)
        cur.pop()
    }
}

function update(arr) {
    let k = arr.join(',')
    if(!vis[k]) {
        ans.push([...arr])
        vis[k] = 1
    }
}

```