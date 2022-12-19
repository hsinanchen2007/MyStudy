### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {string[]} strs
 * @return {string[][]}
 * 
 */

// 用map试一试
var groupAnagrams = function(strs) {
  let result = []
  if (!strs.length) {
      return result
  }
  let map = new Map()
  strs.map(item => {
      let tempStr = item.split('').sort((x, y) => x.charCodeAt() - y.charCodeAt()).join('')
      if (!map.has(tempStr)) {
          map.set(tempStr, [item])
      } else {
          let arr = map.get(tempStr)
          arr.push(item)
          map.set(tempStr, arr)
      }
  })
  for (item of map.values()) {
      result.push(item)
  }
  return result
};
// var groupAnagrams = function(strs) {
//   // 格式化
//   let arr = strs.map((item, index) => {
//       return {
//           index:index,
//           items: [...item]
//       }
//   })
//   for (let i = 0; i < arr.length; i++) {
//     arr[i].items = arr[i].items.sort((x, y) => x.charCodeAt() - y.charCodeAt())
//     arr[i].str = arr[i].items.join('')
//   }
//   // 筛选
//   let result = []
//   for (let i = 0; i < arr.length; i++) {
//     let tempArr = []
//     for (let j = i+1; j < arr.length-1; j++) {
//       if (arr[i].str === arr[j].str || (arr[i].str.length ===0 && arr[j].length === 0) ) {
//         tempArr.push(arr[j])
//         arr.splice(j, 1)
//         j--
//       }
//     }
//     tempArr.push(arr[i])
//     arr.splice(i, 1)
//     i--
//     result.push(tempArr)
//   }
//   // 整理
//   result.map(item => {
//     let tempArr = []
//     item.map(itm => {
//       tempArr.push(strs[itm.index])
//     })
//     arr.push(tempArr)
//   })
//   return arr
// };
```