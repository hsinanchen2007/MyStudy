用纸画一下n为1 2 3 4时候的情况就清楚了，但是写起来很麻烦，应该还能优化

```
var getPermutation = function(n, k) {
  if (n === null || k === null) {
    return ''
  }
  
  let result = []
  
  // 把1-n的数组放到pool里面 等待取出
  let pool = []
  for (let i=0; i<n; i++) {
    pool[i] = i + 1
  }
  
  // 求一个n-1的阶乘 用来判断从第几位 位从高到低
  let factorial = 1
  for (let i=n-1; i>=2; i--) {
    factorial *= i
  }
  // 每次算完一位 下一位的阶乘变小 因为组合数变少
  let divisor = n - 1
  
  for (let i=1; i<=n; i++) {
    // 判断在pool里的下标 如果小于0 要倒着取 这步调试了很久
    let index = Math.ceil(k / factorial) - 1
    if (index < 0) {
      index = pool.length + index
    }
    
    result.push(pool[index])
    // 用过的数字去掉
    pool.splice(index, 1)
    
    // 求下一位的排列组合 先取余 更新阶乘值
    k %= factorial
    factorial /= divisor
    divisor--
  }
  
  return result.join('')
};
```
