### 解题思路
等差数列求和公式的运用，首项加末项乘以项数除以二，脱嘴而出。

首先算出能够分满的最大的轮数

然后再分最后一轮，每个人最后一轮分得的糖果数加上之前分得的就是最终的糖果数

### 代码

```javascript
/**
 * @param {number} candies
 * @param {number} num_people
 * @return {number[]}
 */
var distributeCandies = function(candies, num_people) {
  let height = 0;
  // 算出能够分满的轮数
  while (candies >= ((1 + height * num_people) * height * num_people) / 2) {
    height++;
  }
  height--;
  // 最后一轮分时剩下的糖果个数
  let left = candies - ((1 + height * num_people) * height * num_people) / 2;
  let rtn = [];
  // 最后一轮进行分糖果
  for (let i = 1; i <= num_people; i++) {
    // 之前分到糖果的数量
    let sum = height*i+num_people*(0+height-1)*height/2;
    if (left > 0) {
      let temp = (height) * num_people + i;
      // 剩下的糖果数大于应得的糖果数
      if (left>temp) {
        left = left-temp;
        sum = sum+temp;
      } else {
        // 剩下的糖果数不够应得的，则剩下的全部分给他
        sum = sum + left;
        left = left-temp;
      }
    }
    rtn.push(sum)
  }
  return rtn
};
```