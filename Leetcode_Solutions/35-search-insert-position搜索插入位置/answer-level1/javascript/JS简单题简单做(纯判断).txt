```javascript []
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    for (let i = 0; i < nums.length; i++) {
        if (nums[i] !== target) {
            if(target > nums[nums.length - 1]){
                return nums.length
            }else{
               if (target < nums[i]) {
                    return i
                } 
            }
        }else{
            return nums.indexOf(target)
            break;
        }
    }
};
```

![WX20190917-160443.png](https://pic.leetcode-cn.com/ce2f116d276be3ed609c7cbc68e4d54a82025e793b372de2494b7a3dcf52ca6a-WX20190917-160443.png)


