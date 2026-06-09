解题思路：
1.利用sort排序，找出字符串最短的一项
2.for循环该项，截取该项的每一个字符与数组中剩余项对应的位置字符进行比较
```
var longestCommonPrefix = function(strs) {
  let commonPrefix = ''
  let isContinue = true;
  if (strs.length > 0) {
    var compare = (a, b) => {
      if (a.length < b.length){
        return -1
      } else if (a.length > b.length) {
        return 1
      } else {
        return 0
      }
    }
    strs.sort(compare)
    for (let i = 0; i < strs[0].length; i++) {
        if (isContinue) {
            let str = strs[0].slice(i, i + 1)
            let isAdd = true
            for (let j = 1; j < strs.length; j++) {
                if (str !== strs[j].slice(i, i + 1)) {
                    isContinue = false
                    isAdd = false
                    break
                }
            }
            if (isAdd) {
                commonPrefix += str
            }
        } else {
            break
        }
    }
  }
  return commonPrefix
};
```
