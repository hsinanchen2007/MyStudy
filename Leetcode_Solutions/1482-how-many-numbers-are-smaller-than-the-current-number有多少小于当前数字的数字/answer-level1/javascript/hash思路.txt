### 解题思路

由于数据规模较小，牺牲空间建立hash，然后从大数往小数遍历，维护小于的数量。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var smallerNumbersThanCurrent = function(nums) {
    const hash = {};
    const len = nums.length;
    let count = 0;
    const records = {};
    nums.forEach(t => {
        if (hash[t]) { 
            hash[t]++;
        } else hash[t] = 1;
    })
    for(let i = 100; i>=0 ;i--) {
        if (hash[i]) {
            count += hash[i];
            records[i] = len - count;
        }
    }
    return nums.map(t => records[t])
};
```