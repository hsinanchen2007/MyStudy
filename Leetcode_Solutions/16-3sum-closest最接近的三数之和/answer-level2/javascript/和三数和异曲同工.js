### 解题思路
1. res 负责记录循环期间三数和减target的绝对值最小时的三数和
2. 数组从小到大排序
3. 三数和小于target, L左指针右移，反之，右指针左移
4. 如果三数和等于target，直接返回res

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function(nums, target) {
    let i, L, R, min, sum=0
    let newArr = nums.sort((a,b)=>{return a-b})
    let res = nums[0] + nums[1] + nums[nums.length - 1]
    for(i = 0; i < newArr.length; i++){
        L = i + 1
        R = newArr.length - 1
        while(L < R){
            sum = newArr[i] + newArr[L] + newArr[R]
            if(Math.abs(target - res) >= Math.abs(target - sum)){res = sum}
            if(sum === target){
                return res
            }else if(sum > target){
                R --
            }else if(sum < target){
                L ++
            }
        }
    }
    return res
};
```