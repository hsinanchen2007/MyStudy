### 解题思路
就先假设人无限，按照[1,2,3,4,5,....] 生成数组，得到最终的数组之后，再按人数取余遍历。

### 代码

```javascript
/**
 * @param {number} candies
 * @param {number} num_people
 * @return {number[]}
 */
var distributeCandies = function (candies, num_people) {
  if (candies === 0) {
    return new Array(num_people).fill(0)
  }
  let index = 1
  let arr = [1]
  candies -= index
  while (candies > 0) {
    index++
    if (candies > index) {
      candies -= index
      arr.push(index)
    } else {
      arr.push(candies)
      candies = 0
    }
  }
  let res = new Array(num_people).fill(0)
  for (let i = 0; i < arr.length; i++) {
    res[i % num_people] = res[i % num_people] > 0 ? res[i % num_people] += arr[i] : arr[i]
  }
  return res
};
```