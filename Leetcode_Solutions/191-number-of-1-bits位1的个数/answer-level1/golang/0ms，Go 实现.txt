
![image.png](https://pic.leetcode-cn.com/b99690bbe3d8ae421d927f61af2e20c7ead61f27189c97e5460c765f7e9ed524-image.png)

```
func hammingWeight(num uint32) int {
    cnt := 0
    for num != 0 {
        if num&1 == 1 {
            cnt++
        }
        num >>= 1
    }
    return cnt
}
```