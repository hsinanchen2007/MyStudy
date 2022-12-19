### 解题思路
week 179 第二题
模拟灯亮情况生成一个 灯的数组 `[0, 0, 0, 0, 0] ` 如果灯亮了，0 变成 1.
遍历亮灯顺序数组，维护一个变量 last 用来记录末尾亮了的灯是哪一盏。
因为只要末尾的灯前面没有不亮的灯，就能满足全部亮灯都是蓝色的条件
所以会出现两个满足条件的 case
1. 所有灯都亮了，数组内没有 0
2. 部分灯亮，0 没有出现在 last 之前。即 `[0 ,1 ,1 ,1 ,last ,0]`，像这种情况 last 前面出现了 0 就是不符合条件的。
亮灯顺序的数组遍历一遍，如果满足以上条件就加一，就能获得结果， 时间复杂度 O（0）
### 代码

```javascript
/**
 * @param {number[]} light
 * @return {number}
 */
var numTimesAllBlue = function(light) {
  let arr = new Array(light.length).fill(0)
  let res = 0
  let last = 0
  for (let i in light) {
      arr[light[i] - 1] = 1
      last = Math.max(light[i] - 1, last)
      arr.indexOf(0) > last && res++
      arr.indexOf(0) < 0 && res++
  }
  return res
};
```