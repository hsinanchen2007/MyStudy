### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var subarraySum = function (nums, k) {
  const cache = new Map();
  cache.set(0, 1);
  const len = nums.length;
  let count = 0;
  let temp = 0;
  for (let i = 0; i < len; i++) {
    temp=temp+nums[i];
    if(cache.has(temp-k)){
      count =count+ cache.get(temp-k);
    }
    if(cache.has(temp)){
      cache.set(temp,cache.get(temp)+1);
    } else {
      cache.set(temp,1);
    }
  }
  return count;
};
```
> 假设数组长度为`N`,第`a`个元素到第`b`个元素组成的子数组的和为目标`k`
> 如下关系成立 `sum(1,b)=sum(1,a-1)+sum(a,b)=sum(1,a-1)+k`
> 因此，缓存前`m`个数之和出现次数为`s`，计算出前`n`个之和，如果`sum(1,n)-k`在缓存的数据中，则存在一个`l`，满足`sum(1,l)=sum(1,n)-k`,
> 即，`sum(l+1,n)=sum(1,n)-sum(1,l)=k`