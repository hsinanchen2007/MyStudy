### 解题思路
想到的两种解法：
 1. 是最先容易想到的一种，即先把数组过滤成正整数，再进行升序排列，然后遍历后一个值减前一个值进行筛选。
   这种解法问题在于排序多消耗了遍历次数。
2. 这个在第一种解法基础上优化了一下，利用选择排序的原理（即每次遍历都会把最小值放到最左边），因此可以边遍历边对比值，从而减少遍历次数。
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
<!-- 解法二代码 -->
var firstMissingPositive = function(nums) {
    // 利用选择排序的原理，减少数组遍历次数
    nums = nums.filter(item=>{ return item > 0;})
    let min;
    for(let i = 0;i<nums.length; i++){
        min = nums[i];
        for(let j = i+1; j<nums.length; j++){
            if(min > nums[j]){                
                let temp = min;
                min = nums[j];
                nums[j] = temp;
            }
        }
        // 当把后面的值都遍历完后，当前值和标记出来的值交换位置
        nums[i] = min;
        if(i>0){
            if(nums[i] - nums[i-1]>1){
                return nums[i-1] + 1;
            }
        }else{ // 只遍历出第一个最小值时
            if(min !== 1){
                return 1;
            }
        }
    }
    // 如果数组是连续的正整数,注意：此处不能用数组长度直接+1，因为会有相同元素的数组情况，如[1,1]
    return nums.length ? nums.pop() +1 : 1;
};
```