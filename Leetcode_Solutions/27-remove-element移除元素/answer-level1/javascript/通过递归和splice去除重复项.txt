### 解题思路
![image.png](https://pic.leetcode-cn.com/cac0eb2a10ac49bad20c8cf75c328a0c13ace4b1fc44cd07925c81b1be680a68-image.png)

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    if(nums.indexOf(val) === -1){
        return nums.length
    }else{
        nums.splice(nums.indexOf(val),1)
        removeElement(nums,val)
    }
};
```