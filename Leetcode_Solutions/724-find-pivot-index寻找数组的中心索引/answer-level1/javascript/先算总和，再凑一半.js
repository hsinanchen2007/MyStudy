### 解题思路
![image.png](https://pic.leetcode-cn.com/9e0eb8c290a91e9b53d9fa3a39b8501565fe8b4b3627cc0b830f4b4d0c237ae9-image.png)


### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var pivotIndex = function(nums) {
    let sum = 0;
    let ans = 0;
    let idx = -1;
    nums.forEach(val => {
        sum += val;
    })

    for (let i = 0; i < nums.length; i++) {
        if (ans === (sum - nums[i]) / 2) {
            idx = i;
            break;
        }
        ans += nums[i];
    }
    return idx;
};
```