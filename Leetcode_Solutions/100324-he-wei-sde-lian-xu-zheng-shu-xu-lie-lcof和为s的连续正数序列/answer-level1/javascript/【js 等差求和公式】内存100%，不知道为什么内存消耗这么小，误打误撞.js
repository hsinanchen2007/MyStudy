### 解题思路
借鉴了之前糖果题的解方程思路
等差数列求和，解出最后一个数字，如果是整数就ok
```
    从第i位开始，end结束，（i + end) * (end - i + 1) = 2 * target
    i已知，所以该式是end的一元二次方程，正常解方程即可
    其中，因为都是正整数，所以end的负值直接舍掉
```
值得提到的是循环的次数，是Math.ceil(target/2），只取一半就可以

### 代码

```javascript
/**
 * @param {number} target
 * @return {number[][]}
 */
var findContinuousSequence = function(target) {
  let numberArr = []
  if (target === 1) return []
  if (target === 2) return []
  for (let i = 1; i < Math.ceil(target/2) ; i++) {
    const end = (-1 + Math.sqrt((1 + 4 * (i * i - i + 2 * target)))) / 2
    if (parseInt(end) === end) {
      const number = Array.from({length: (end - i + 1)}, (item, index) => (index + i))
      numberArr.push(number)
    }
  }
  return numberArr
};
```