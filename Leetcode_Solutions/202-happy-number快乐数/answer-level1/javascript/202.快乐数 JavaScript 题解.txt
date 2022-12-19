
![javascript.jpg](https://pic.leetcode-cn.com/ba0ff6c4c829f066b3f9c0f90a99508114b99f0766a89df1aec839e6069d0e06-javascript.jpg)  

成功的例子(19)  

- 19 => 1 + 81
- 82 => 64 + 4
- 68 => 36 + 64
- 100 => 1 + 0 + 0  
  
失败的例子(20)  
  
- 20 => 4 + 0
- 4 => 16
- 16 => 1 + 36
- 37 => 9 + 49
- 58 => 25 + 64
- 89 => 64 + 81
- 145 => 1 + 16 + 25
- 42 => 16 + 4
- 20 可以看到, 20再次重复出现了, 所以永远不可能等于1  
  
> 那思路就是利用`set.has()`判断重复, 就`return false`  

```javascript []
const isHappy = n => {
  let set = new Set(), sum
  n += ''
  while (sum !== 1) {
    sum = 0
    for (let i = 0; i < n.length; i++) {
      sum += n[i]*n[i]
    }
    n = sum + ''
    if (set.has(sum)) return false
    set.add(sum)
  }
  return true
}
```
