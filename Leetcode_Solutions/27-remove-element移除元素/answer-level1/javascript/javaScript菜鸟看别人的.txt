### 解题思路
先遍历，再通过下标剔除不一样的元素，最后计数组长度

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    let conunt = 0;
    for(let num of nums) {
        if(num != val) {
            nums[conunt] = num;
            conunt++;
        }
    }
    return conunt;  
};
```