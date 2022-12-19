```
/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
  let result = []
  // 先让数组的每个字符串排序
  let sorted = strs.map(item => item.split('').sort().join(''))
  // 相同字符串在map中的标记
  let index = 0
  let map = new Map()
  
  for (let i=0; i<sorted.length; i++) {
    if (!map.has(sorted[i])) {
      // 这里建立初始的二维数组，并放入第一个字符串，注意是strs原始的，不是排序过的
      if (!result[index]) {
        result[index] = [strs[i]]
      }
      // map中放入新的排序后的字符串，并且更新标记
      map.set(sorted[i], index)
      index++
    } else {
      // 如果是map中已有字符串，直接塞入对应标记的字符串
      result[map.get(sorted[i])].push(strs[i])
    }
  }
  
  return result
};
```
