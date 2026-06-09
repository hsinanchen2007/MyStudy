先上题解

1. 题目要求是找缺失的第一个正数，
2. 先取出数组中所有大于0的项 
3. 按数组索引存入新数组中
4. 新数组中缺失的第一项即为解

```
var firstMissingPositive = function(nums) {
    if(nums.length === 0) return 1
    if(nums.length === 1 && nums[0] <= 0) return 1
    let arr = []
    nums.forEach((v) => {
        if(v >=1) {
            arr[v] = 1
        }
    })

    if(!arr.length) return 1

    for(let i = 1; i<arr.length; i++) {
        if(!arr[i]) {
            return i
        }
    }
    return arr.length
};
```

![image.png](https://pic.leetcode-cn.com/751a7436940a226c4e456553086c8500bc54aa1f36601e73eef075d28f9f7ec0-image.png)
