### 解题思路

题目：假设数组是非空的，并且给定的数组总是存在多数元素
so:只需要处理前一半数组对象，计算数组对象的个数进行判断即可

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    let _res = {};
    let len = nums.length;
    let half = Math.ceil(len /2);

    if(!len) return nums;
    let res = null;
    for(let i=0;i<half;i++) {
        let item = nums[i];
        if(!_res[item]) {
            let _count = 0;
            for(let j=i;j<len;j++ ) {
                if(nums[j] === item) {
                    _count++;
                }
            }
            _res[item] = _count; 
            if(_count >= half) {
                i==half;
                res = item;
            }
        }
    }
    return res;    
};
```