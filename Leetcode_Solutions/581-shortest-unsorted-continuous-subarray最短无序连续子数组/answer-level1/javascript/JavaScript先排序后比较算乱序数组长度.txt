### 解题思路
先给数组排序，然后和旧数组的每一项比较，分别从前往后和从后往前依次比较，获取两端第一个不同的数字下标进而算出乱序数组的长度。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var findUnsortedSubarray = function(nums) {
    //拷贝一份数组后进行排序
    var nums2 = nums.slice(0).sort((a,b)=>a-b);
    var len = nums.length;
    var i =0;
    var j = len-1;
    //从前往后比
    while(nums[i]===nums2[i] && i<len){
        i++;
    }
    if(i===len)return 0;
    //从后往前比
    while(nums[j]===nums2[j] && j>=0){
        j--;
    }
    return j-i+1;

};
```
> 执行用时 :116 ms, 在所有 JavaScript 提交中击败了63.52%的用户  
> 内存消耗 :38.6 MB, 在所有 JavaScript 提交中击败了49.57%的用户

优化方案？