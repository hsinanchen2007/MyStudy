### 解题思路
1，arr数组去重得到key数组
2，出现次数count数组与key数组长度相同（下标对应，重置为0）
3，遍历arr统计次数（indexOf可返回元素所在数组位置的下标）
4，判断count数组中是否有重复项

### 代码

```javascript
/**
 * @param {number[]} arr
 * @return {boolean}
 */
var uniqueOccurrences = function(arr) {
    
  let keyArr = []
  let countArr = []
  keyArr = Array.from(new Set(arr))
  for (let i = 0; i < keyArr.length; i++) {
    countArr.push(0)
  }
  for (let i = 0; i < arr.length; i++) {
    countArr[keyArr.indexOf(arr[i])]++
  }

  if (Array.from(new Set(countArr)).length == countArr.length) return true
  else return false
};
```