### 解题思路
![image.png](https://pic.leetcode-cn.com/ba19c4617d3fd794e2b3c1e6e25cbeef318ebcc7ad4224d0124878bc2026da89-image.png)

- 通过toString().length 得到长度
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findNumbers = function(nums) {
    let sum = 0
    for(let i = 0; i < nums.length;i++){
        if(nums[i].toString().length % 2 == 0){
            sum++
        }
    }
    return sum
};
```