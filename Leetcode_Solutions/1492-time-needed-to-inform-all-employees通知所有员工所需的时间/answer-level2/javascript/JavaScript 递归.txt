### 解题思路
week 179 第三题
创建一个哈希表，用来记录对应上司手下的位置。
每一个员工递归，获得对应员工手下最长时长。
时间复杂度 O（log n）
### 代码

```javascript
/**
 * @param {number} n
 * @param {number} headID
 * @param {number[]} manager
 * @param {number[]} informTime
 * @return {number}
 */
var numOfMinutes = function(n, headID, manager, informTime) {
  let hash = {}
  manager.forEach((ele, index) => {
      if(!hash[ele]) hash[ele] = [index]
      else hash[ele].push(index)
  })
  function count(m){
      if(!hash[m]) return 0
      let arr = [0]
      hash[m].forEach(ele => {
          arr.push(count(ele))
      })
      return informTime[m] + Math.max(...arr)
  }
  return count(headID)
};
```