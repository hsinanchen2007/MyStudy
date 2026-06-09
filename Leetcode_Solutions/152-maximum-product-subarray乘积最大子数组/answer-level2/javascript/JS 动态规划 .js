### 解题思路
/**
1. 找状态
 *      以nums[i]为结尾的所有数组中最大值为 dpMax = max(num[i], max(dpMax[i-1] * num[i], dpMin[i-1]*nums[i])) 
 *      以nums[i]为结尾的所有数组中最小值为 dpMin = min(num[i], min(dpMax[i-1] * num[i], dpMin[i-1]*nums[i])) 
 *          作为负数的因数，此处dpMin 的作用就是，保存将 包含nums[i]的所有结果中的最小值记录下来（主要是想记录最小的负数），然后如              果后面乘以一个负数的话，有可能会变成最大的数字！
 *      
2. 转移方程
 *      dpMax[i] = max(num[i], max(dpMax[i-1] * num[i], dpMin[i-1]*nums[i])) 
 *      dpMinmin[i] = min(num[i], min(dpMax[i-1] * num[i], dpMin[i-1]*nums[i]))
 *      max = max(max,dpMax[i]) 
3. 初始状态和边界值
 *      dpMax[0] = nums[0]
 *      dpMinmin[0] = nums[0]
 *      max =  dpMax[0]
4. 计算顺序
 *      从小到大
 */

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
/**
 * 1.找状态
 *      以nums[i]为结尾的所有数组中最大值为 dpMax = max(num[i], max(dpMax[i-1] * num[i], dpMin[i-1]*nums[i])) 
 *      以nums[i]为结尾的所有数组中最小值为 dpMin = min(num[i], min(dpMax[i-1] * num[i], dpMin[i-1]*nums[i])) 作为负数的因数
 *      
 * 2.转移方程
 *      dpMax[i] = max(num[i], max(dpMax[i-1] * num[i], dpMin[i-1]*nums[i])) 
 *      dpMinmin[i] = min(num[i], min(dpMax[i-1] * num[i], dpMin[i-1]*nums[i]))
 *      max = max(max,dpMax[i]) 
 * 3.初始状态和边界值
 *      dpMax[0] = nums[0]
 *      dpMinmin[0] = nums[0]
 *      max =  dpMax[0]
 * 4.计算顺序
 *      从小到大
 */
var maxProduct = function(nums) {
    let n = nums.length;
    if(n == 0){
        return 0;
    }
    let dpMax = [];
    dpMax[0] = nums[0];
    let dpMin = [];
    dpMin[0] = nums[0];
    max = dpMax[0]
    for(let i = 1; i<n; i++){
        dpMax[i] = Math.max(nums[i], Math.max(dpMax[i-1] * nums[i], dpMin[i-1] * nums[i]))
        dpMin[i] = Math.min(nums[i], Math.min(dpMax[i-1] * nums[i], dpMin[i-1] * nums[i]))
        max = Math.max(max, dpMax[i]);
    }
    return max
};







```