## 思路

题干中说按大小顺序排序，可以找到规律，所有排列情况由*n*个子集组成（每个子集首数字相同），每个子集有*n!*个元素，可以推算出第*k*个元素可以简要表达为

`getPermutation(n, k) = n + getPermutation(n - 1, k % n!);`

```javascript []
var getPermutation = function(n, k) {
  // 出现的所有数字，之后从中取值
  const nums = [...Array(n)].map((vo, i) => i + 1);

  // 结果，应有nums组成，并且不重复
  const re = [];

  let nextK = k;
  for (let i = n; i > 0; i--) {
    // 首字符相同数字的数量
    const factorialN = factorial(i - 1);
    const num = Math.ceil(nextK / factorialN);
    re.push(nums.splice(num - 1, 1));
    nextK = (nextK % factorialN) || factorialN;
  }

  return re.join('');
};

function factorial(n) {
  if (n <= 1) {
    return 1;
  }
  return factorial(n - 1) * n;
}
```

- 空间复杂度*O(n)*
- 时间复杂度*O(n)*