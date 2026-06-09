### 解题思路

![image.png](https://pic.leetcode-cn.com/a56e043334d50c9e6ae80ad99a66577137a0752ee1bb21971d66c266eb2ccd94-image.png)

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} t
 * @return {boolean}
 */
var containsNearbyAlmostDuplicate = function(nums, k, t) {
    var map = new Map();
    for(let i = 1;i<nums.length;i++){
        for(let j=0;j<=i;j++){
            if(i!=j&&Math.abs(nums[i]-nums[j])<=t&&i-j<=k){
                return true
            }
        }
    }
    return false
};
```