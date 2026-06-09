![image.png](https://pic.leetcode-cn.com/32b113d47cf5bc564ab0116fca06f5ff41de31979b6943da8609db264c4c2255-image.png)

### 解题思路

题目中说到长度为n的数组存放0~n-1的数，那么我可以创建一个长度为n的数组
我可以将数组的下标对应每种数字，值对应数字出现的次数

先初始化数组每个元素为0，表示开始所有种类的数字出现的次数为0（包括原数组不存在的数字）
遍历原数组 nums[i]即下标，次数+1表示出现了一次
当我遍历到第一个重复了的数时值为2了我就可以将它的下标（也就是nums[i]）返回即可

用到一个长度为n的数组 空间复杂度O(n) 遍历一次原数组 时间复杂度O(n) 
时间空间复杂度还好不知道是不是用js做题的人太少了

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findRepeatNumber = function(nums) {
    let arr = [];
    for(let i=0;i<nums.length;i++){
        arr[i] = 0;
    }
    for(let i=0;i<nums.length;i++){
        arr[nums[i]]++;
        if(arr[nums[i]]>1){
            return nums[i];
        }
    }
};
```