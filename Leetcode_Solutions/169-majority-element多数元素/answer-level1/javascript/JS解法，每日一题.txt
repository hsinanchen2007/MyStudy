### 解题思路
第一种：题目给出多数元素个数大于n/2，排序取中位数即为多数元素；

第二种：标记第一个元素向后循环对比，记录次数，相同则记录加一，不同减一，当记录为零时标记元素改为当前元素记录为一，继续运行，结束后标记元素即为多数元素。

（第一种方法思路简单，第二种方法用时和消耗更少）
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    // nums.sort((a,b)=>a-b);//第一种解法
    // return nums[Math.floor(nums.length/2)]

    let a=nums[0],n=1;//第二种解法
    for(let i=1;i<nums.length;i++){
        if(n===0){
            a=nums[i]
            n=1
        }else if(a===nums[i]){
            n++
        }else{
            n--
        }
    }
    return a
};
```