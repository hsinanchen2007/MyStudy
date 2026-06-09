### 执行时间
![image.png](https://pic.leetcode-cn.com/784612e7b584f3dc78aa3ef0d9cb3c253a8c82ce88c1f40d226ee99478ce88bd-image.png)

### 解题思路
参考的[加油coding](https://leetcode-cn.com/problems/he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof/solution/javascripthua-dong-chuang-kou-hen-rong-yi-li-jie-d/)的代码。感觉很好就记录一下

### 代码

```javascript
/**
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence = function (target) {
  let index = target % 2 === 0 ? target / 2 : (target / 2 | 0) + 1
  let res = []
  let temp = []
  let sum = 0
  for (let i = 1; i <= index; i++) {
    temp.push(i)
    sum = sum + i
    while (sum > target) {
      sum -= temp[0]
      temp.shift()
    }
    if (sum === target) {
      temp.length >= 2 && res.push([...temp])
    }
  }
  return res;
};
```