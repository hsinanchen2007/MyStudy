### 解题思路
![image.png](https://pic.leetcode-cn.com/bae77137f09ea50c0e6b66c67c2e7cc4608dbd4bcc1881f250c93e4d6729781b-image.png)

新建hashMap， nums中的数字为key  出现的次数为 value。
一次遍历，找到 hashMap 中出现次数最多的元素


### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    if (nums.length === 1) return nums[0];
    let hash = {}, max = 0, res;
    for (let i = 0; i < nums.length; i++) {
        if (hash[nums[i]]) {
            hash[nums[i]]++;
            if (hash[nums[i]] > max) {
                max = hash[nums[i]];
                res = nums[i];
            }
        } else {
            hash[nums[i]] = 1;
        }
    }
    return res;
};
```