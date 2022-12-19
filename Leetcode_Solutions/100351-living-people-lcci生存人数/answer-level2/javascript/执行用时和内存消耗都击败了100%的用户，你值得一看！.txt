### 解题思路
首先计算出出生时间中的最小值minBirth，为了减少辅助数组arr的内存浪费。
将每个人的所有存活年份都遍历到一个辅助数组中，出现一次，在辅助数组的（年份-最小年份）下标上的数值+1，然后再遍历过程中记录下当前存活人数中最多的年份的存活人数num，和最小的存活人数最多的年份min，最后将min+minBirth返回出去就是结果
思想类似于计数排序。

### 代码

```javascript
/**
 * @param {number[]} birth
 * @param {number[]} death
 * @return {number}
 */
var maxAliveYear = function(birth, death) {
    //arr为辅助数组，num为当前存活人数最多的年份的存活人数，min为最小的存活人数最多的年份，minBirth为出生时间中的最小值（为了减小arr的内存浪费）
    let arr = [], num = 0, min = 0, minBirth = birth[0];
    for(let i = 1; i < birth.length; i ++) {//寻找出生时间的最小值
        if(birth[i] < minBirth) minBirth = birth[i];
    }
    for(let i = 0; i < birth.length; i ++) {
        for(let j = birth[i] - minBirth; j <= death[i] - minBirth; j ++) {
            if(arr[j] == undefined) arr[j] = 0;
            arr[j] ++;
            if(arr[j] > num) {
                num = arr[j];
                min = j;
            } else if(arr[j] == num) {
                if(j < min) min = j;
            }
        }
    }
    return min + minBirth;
};
```