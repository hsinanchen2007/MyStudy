### 解题思路
利益reduce累加器，定义_arr和_index记录可能出现的最大值和对应的索引
从左向右遍历，检测无重复值则进行累加，有重复值则截取当前保存字符串靠右的不重复值，并新增新的_arr数组元素，保存出现过的最大值。遍历完成后**返回_arr数组中的最大值**

### 代码

```javascript
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    let _arr = [0],_index = 0
      s.split('')
        .reduce((prev, cur) => {
          const subindex = prev.indexOf(cur)
          if (subindex > -1) {
            _arr.push(prev.length - subindex)
            _index++
            return prev.substring(subindex + 1) + cur
          } else {
            _arr[_index]++
            return prev + cur
          }
        }, '')
      return Math.max(..._arr)
};
```