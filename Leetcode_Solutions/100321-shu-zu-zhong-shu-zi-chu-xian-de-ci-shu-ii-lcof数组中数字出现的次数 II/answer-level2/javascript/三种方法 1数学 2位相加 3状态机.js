**方法一 数学计算**
计算所有数字和 sumAll = sumRepeat * 3 + single
去重后数字和   sumSingle = sumRepeat + single
相减得到 sumAll - sumSingle = sumRepeat * 2
求出sumRepeat 带入第一个算式 可得single

缺点：数字太大相加可能溢出

```
var singleNumber = function(nums) {
  if (!nums) {
    return
  }
  
  let sumAll = nums.reduce((a, b) => a + b, 0)
  let sumSingle = [...new Set(nums)].reduce((a, b) => a + b, 0)
  let sumRepeat = (sumAll - sumSingle) / 2
  let result = sumAll - sumRepeat * 3
  
  return result
};
```

**方法二 位相加**
定义一个数组，存放每个数字的二进制每一位，举个例子[3,4,3,3]
 11
 11
100
 11
将各位相加得
133
再将各位取余3得
100
重复数字位的都是3的倍数，取余后则为唯一数字的二进制表示

缺点：写起来麻烦

```
var singleNumber = function(nums) {
  if (!nums) {
    return
  }
  
  let length = nums.length
  
  let revDigit = []
  
  for (let i=0; i<length; i++) {
    let binaryStr = nums[i].toString(2)
    let binaryLength = binaryStr.length
    let revIndex = binaryLength - 1 - j
    for (let j=0; j<binaryLength; j++) {
      if (revDigit[revIndex] === undefined) {
        revDigit[binaryLength - 1 - j] = 0
      }
      revDigit[revIndex] = +revDigit[revIndex] + +binaryStr[j]
    }
  }
  
  for (let i=0; i<revDigit.length; i++) {
    revDigit[i] = revDigit[i] % 3
  }
  
  let binaryStr = revDigit.reverse().join('')
  
  return parseInt(binaryStr, 2)
};
```

**方法三 状态机**

缺点：难想出来

```
var singleNumber = function(nums) {
  if (!nums) {
    return
  }
  
  let a = 0
  let b = 0
  
  for (let num of nums) {
    a = (a ^ num) & ~b
    b = (b ^ num) & ~a
  }
  
  return a
};
```

**方法四 计数排序**
统计每个数字出现的次数，出现一次的数字就是唯一的

缺点：需要额外空间比较多