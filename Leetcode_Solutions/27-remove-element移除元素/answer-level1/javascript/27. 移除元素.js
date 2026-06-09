### 解题思路
splice数组移除元素，如果存在就移除
![image.png](https://pic.leetcode-cn.com/1e075a101bb2be5160a7c8e3e702b4ec3a81ab17c9ffcd0b216bb5eb612a4169-image.png)


### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    while(nums.indexOf(val)!=-1){
        let i = nums.indexOf(val);
        nums.splice(i,1)
    }
    return nums.length
};
```