### 解题思路
首先，2位数一下天然满足条件。
然后，如果前两位就不满足。取最小的。扣除一次机会
从第三位开始遍历。如果不满足条件。与更往前的一位对比。确定是取大数还是取小数作为后面继续遍历的开头。继续！

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {boolean}
 */
var checkPossibility = function(nums) {
    let len = nums.length;
    if(len < 3){
        return true;
    }
    let count = 1;
    let last = 0;
    if(nums[0] > nums[1]){
        count--;
        nums[0] = nums[1];
        last = Math.min(nums[0],nums[1]);
    }
    last = nums[1];
    for(let i = 2; i < len; ++i){
        if(nums[i] >= last){
            last = nums[i];
        }else{
            let curr = Math.min(nums[i],nums[i - 1]);
            if(curr >= nums[i - 2]){
                last = nums[i] = nums[i - 1] = curr;
            }else{
                curr = Math.max(nums[i],nums[i - 1]);
                last = nums[i] = nums[i - 1] = curr;
            }
            count--;
        }
        if(count < 0){
            return false;
        }
    }
    return true;
};
```