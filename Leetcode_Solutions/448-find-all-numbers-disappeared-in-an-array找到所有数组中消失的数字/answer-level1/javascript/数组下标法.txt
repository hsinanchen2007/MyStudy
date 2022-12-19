### 代码

```javascript
var findDisappearedNumbers = function(nums) {
    const res = []
    for (let i = 1; i <= nums.length; i++) {
        if (nums.indexOf(i) === -1) {
            res.push(i)
        }
    }
    return res
};
```
时间复杂度：O(n^2)
空间复杂度：O(1)(题目有提醒)