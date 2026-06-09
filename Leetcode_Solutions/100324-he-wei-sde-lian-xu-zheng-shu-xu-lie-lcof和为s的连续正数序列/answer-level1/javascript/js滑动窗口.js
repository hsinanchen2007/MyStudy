### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence = function(target) {
    let left = 1
    let right = 0
    let sum = 0
    let ans = []
    // 最大不超过target的一半
    while(right <= Math.round(target / 2)){
        if(sum === target){
            // sum等于目标数
            let temp = []
            for(let i=left; i<=right; i++){
                temp.push(i)
            }
            if(temp.length) ans.push(temp)
            sum -= left
            left++
        }

        // sum大于目标数，左边-
        while(sum > target){
            sum -= left
            left++
        }

        // sum小于目标数，右边+
        while(sum < target){    
            right++
            sum += right
        }
    }
    return ans
};
```