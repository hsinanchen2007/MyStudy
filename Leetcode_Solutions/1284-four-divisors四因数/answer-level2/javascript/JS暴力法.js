### 解题思路
1. 计算每个数字的因数
2. 因数数量不等4时直接return 0
3. 将所有因数相加计算结果相加得到答案

### 代码

```javascript
var sumFourDivisors = function(nums) {
    function get4Factors(n) {
      let left = 1, right = n;
      let factors = [];
      while (left < right) {
        if (n % left === 0) {
          if (n / left === left) return 0;
          factors.push(left, n / left);
          if (factors.length > 4) return 0;
          right = n / left;
        }
        left++;
      }
      if (factors.length !== 4) return 0;
      return factors.reduce((prev,cur,index,array) => {return prev + cur});
    }
    let res = 0;
    for (let i = 0; i < nums.length; i++) {
      res += get4Factors(nums[i]);
    }
    return res;
  };
```