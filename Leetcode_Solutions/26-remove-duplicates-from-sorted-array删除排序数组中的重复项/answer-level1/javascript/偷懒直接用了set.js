### 解题思路
![image.png](https://pic.leetcode-cn.com/34c4318335874eaec030cc1560846110084a3052670b10cff7dbb85d5b39ad48-image.png)

肯定不是O(1),我再研究研究。。。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    let arr = [...new Set(nums)];
    let len = arr.length;

    for(let i=0;i<len;i++){
        nums[i] = arr[i];
    }
    return len;
};
```