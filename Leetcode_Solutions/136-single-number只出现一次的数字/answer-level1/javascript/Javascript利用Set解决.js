执行用时:76 ms，内存消耗:37.2 MB
```
/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function(nums) {
  const set = new Set()
  
  nums.forEach(num => {
    // 遍历数组，加入set没有的值，删除已存在的值
    set.has(num)? set.delete(num) : set.add(num)
  })

  // 返回set唯一的值
  return [...set][0]
};
```
