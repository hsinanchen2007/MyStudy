### 解题思路
1. 准备一个字典，用于查询之前插入的值情况。(new Map())
2. target - 当前value 得到差值，查询之前的字典中有没有这个差值
3. 如果有，就整合一下数组返回
4. 如果没有，再判断一下字段中是否已经有这个值的索引，有就啥也不做，没有就存起来
5. 循环结束都没找到，则返回空[]
### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
  const map = new Map();
  for(let i = 0; i < nums.length; i++) {
    let diff = target - nums[i]
    let index = map.get(diff)
    if (index !== void 0) {
      return [index, i]
    }
    !map.has(diff) && map.set(nums[i], i)
  }
  return []
};

```