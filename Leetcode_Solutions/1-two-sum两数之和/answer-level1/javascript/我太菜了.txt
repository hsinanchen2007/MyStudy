### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums   给定的整数数组
 * @param {number} target： 期望得到的目标和值
 * @return {number[]}       返回数组中和为target的索引
 * @description:            1、通过entries拿到数组的键值对（index/value），并遍历。
 *                          2、target依次减去数组的每一项，得到差值，并在原数组当中查找是否存在
 *                          3、判断差值是否在数组中存在
 *                          4、存在差与减数相同的情况，所以还需判断差与减数是否为数组的同一项
 */
var twoSum = function(nums, target) {
    for (const item of nums.entries()) {
        let index = nums.indexOf(target - item[1]);
        if (index != -1 && item[0] != index) {
            return [item[0], index];
        }
    }
};
```