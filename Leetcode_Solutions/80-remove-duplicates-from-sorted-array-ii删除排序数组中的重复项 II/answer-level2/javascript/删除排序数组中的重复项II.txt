### 解题思路
- 参考26题，只有一个元素，第二个和第一个比，两个重复元素，第三个和第一个比，还可以类推到3个重复元素（第四个和第一个比）

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    let R, L = 1
    for(R = 2; R < nums.length; R++){
        //nums[R]第三个元素，nums[L-1]第一个元素
        if(nums[R] !== nums[L - 1]){
            L ++
            nums[L] = nums[R]
        }
    }
    return L + 1
};
```