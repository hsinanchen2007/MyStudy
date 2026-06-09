### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    const len = nums.length;
    const result = [];
    if ( len < 3) {
        return result;
    }
    nums.sort((pre, val) => (pre - val));
    let preI = null;
    for (let i=0; i<len-2; i++) {
        let valI = nums[i];
        if (valI > 0) {
            break;
        }
        if (preI === valI) {
            continue;
        }
        preI = valI;
        let l = i + 1;
        let r = len -1;
        while(l < r) {
            let valL = nums[l];
            preL = valL;
            let valR = nums[r];
            let sumVal = valI + valL + valR;
            if (sumVal > 0) {
                r--;
            } else if (sumVal < 0) {
                l++;
            } else {
                result.push([valI, valL, valR]);
                do {
                    l++;
                } while (nums[l] === valL)
            }
        }
    }
    return result;
};
```