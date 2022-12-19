### 解题思路
![image.png](https://pic.leetcode-cn.com/d8d59c704579f67d292dda9168418c88d394681c425e99b1294c745ea938d261-image.png)

- 通过concat 合并数组， 通过new Array新建数组，通过fill（）填充数组

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var decompressRLElist = function(nums) {
    let arr = []
    for(let i = 0 ; i < (nums.length)/2 ; i++){
        arr = arr.concat(new Array(nums[2*i]).fill(nums[2*i+1]))
    }
    return arr
};
```