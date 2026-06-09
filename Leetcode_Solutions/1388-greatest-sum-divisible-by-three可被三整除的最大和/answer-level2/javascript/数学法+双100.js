- sum是数组和
- num1表示数组中除3余数为1的最小的两个数 num1[1]最小
- num2表示数组中除3余数为2的最小的两个数 num2[1]最小
- sum % 3 === 1 则需要减去一个余数为一的数 即 num1[1] 和 num2[0] + num2[1] 中较小的一个
- sum % 3 === 2 则需要减去一个余数为二的数 即 num2[1] 和 num1[0] + num1[1] 中较小的一个
```
var maxSumDivThree = function(nums) {
  let num1 = [10001, 10001]  
  let num2 = [10001, 10001]
  let sum = 0;
  nums.forEach(num => {
    sum += num;
    if (num % 3 === 1) {
      if (num < num1[0]) {
        if (num < num1[1]) {
          num1[0] = num1[1];
          num1[1] = num;
        } else {
          num1[0] = num;
        }
      }
    } else if (num % 3 === 2) {
      if (num < num2[0]) {
        if (num < num2[1]) {
          num2[0] = num2[1];
          num2[1] = num;
        } else {
          num2[0] = num;
        }
      }
    }
  })
  if (sum % 3 === 0) return sum
  else if (sum % 3 === 1) {
    return sum - Math.min(num1[1] < 10001 ? num1[1] : 10001, num2[0] < 10001 ? num2[0] + num2[1] : 10001)
  } else {
    return sum - Math.min(num2[1] < 10001 ? num2[1] : 10001, num1[0] < 10001 ? num1[0] + num1[1] : 10001)
  }
};
```
