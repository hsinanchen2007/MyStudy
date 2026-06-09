### 解题思路
javascript耗时和内存100%。
注意到提示：
2 <= nums.length <= 500
0 <= nums[i] <= 100

可以想到利用计数排序的思想，分101个桶，当前元素值作为桶的下标，元素出现的次数作为桶下标的值。
那么桶的下标小于当前值的所有出现次数累加起来，就是比当前值小出现的次数了。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var smallerNumbersThanCurrent = function(nums) {
    var len = nums.length;
    var tL = 101;// 桶的个数
    var t = [];
    // 初始化桶
    for (var s = 0; s < 101; s++) {
        t[s] = 0;
    }
    for (var i = 0; i < len; i++) {
        t[nums[i]]++
    }
    // 累加
    for (var j = 1; j <= 101; j++) {
        t[j] = t[j - 1] + t[j]; 
    }

    var result = []
    for (var k = 0; k < len; k++) {
        result[k] = nums[k] ? t[nums[k] - 1] : 0;
    }
    return result;
};
```