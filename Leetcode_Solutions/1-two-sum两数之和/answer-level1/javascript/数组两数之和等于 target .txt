### 解题思路
通过 for 循环遍历，获得 num; 用 target - num = gap 取差值；
array.indexOf(gap) !== -1  判断差值是否存在，
array.indexOf(gap) !== i  排除 num 自身。例如特殊情况 [3,3] 6
return indexArr
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    let indexArr = [];
    for(let i=0; i<nums.length; i++){
        let gap = target - nums[i];
        let gapIndex = nums.indexOf(gap);
        if(gapIndex !== -1 && gapIndex !== i){
            indexArr.push(i);
            indexArr.push(gapIndex);
            return indexArr;
        }
    }

};
```