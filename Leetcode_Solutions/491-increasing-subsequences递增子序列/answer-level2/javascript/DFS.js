### 解题思路
代码还是回溯的模版，注意去重用Set记录，如果从本次j开始的循环已经记录过那么就直接跳过

### 代码

```javascript
var findSubsequences = function(nums) {
    let res = [];

    dfs(0, nums, [-101], res);
    return res;
};

function dfs(j, nums, temp, res) {
    if (temp.length > 2) {
        res.push(temp.slice(1));
    }
    let s = new Set();

    for (let i = j; i < nums.length; i++) {
        if (nums[i] < temp[temp.length - 1]) continue;
        if (s.has(nums[i])) continue;

        s.add(nums[i]);
        temp.push(nums[i]);
        dfs(i + 1, nums, temp, res);
        temp.pop();
    }
}
```