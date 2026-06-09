### 解题思路
它想要得到选出两个数最小值后,全部加起来得到最大值

所以要把两个数相差最小的为一对, 从小排到大后, 就可以得到 一个增序数组, 两两一对(1,2),(3,4)(5,6)...

取两两之间的最小值 可以知道 这个数组中 排序为 偶数的 为最小值 ,  所以筛选出偶数项后,把每项加起来就行了.
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var arrayPairSum = function(nums) {
    return nums.sort((a,b)=>a-b).filter((item,index)=> index % 2 === 0).reduce((t,i)=> t+i)
};
```