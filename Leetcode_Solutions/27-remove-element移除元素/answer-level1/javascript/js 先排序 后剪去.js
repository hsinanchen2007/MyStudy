### 解题思路
最开始写的是挨个遍历，找到一个减掉一个，但是这样剪感觉Splice重复太多，有点慢。

改进为先排序，然后indexOf(),找到第一个，再算出重复的次数，再一次性减去，优化之后确实提高不少
事件56ms，超越96%。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    nums.sort((a,b) => a -b)
    let index = nums.indexOf(val);
    let i = index;
    if(index != -1){
        while(nums[i] == val) i++;
        let len = i - index;
        nums.splice(index, len);
    }
    return nums.length;
};
```