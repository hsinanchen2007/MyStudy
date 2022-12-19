### 解题思路
先复制一份数组，复制的时候复制值和索引，之后按值排序，索引自动重排，再遍历索引按在新数组的位置填充res数组；
### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {string[]}
 */
let medal = ["Gold Medal", "Silver Medal", "Bronze Medal"];
var findRelativeRanks = function(nums) {
    let res = [];
    nums.map((value,index)=>[value,index]).sort((pre,cur)=>cur[0]-pre[0]).forEach((value,index)=>{res[value[1]] = index < 3 ? medal[index] : String(index+1)});
    return res;
};
```