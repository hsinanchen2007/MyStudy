
![image.png](https://pic.leetcode-cn.com/304e05d34278e1088e8e75edcbe9516ee5640693ac83dee299cc3142efe4bcf8-image.png)

```
func trailingZeroes(n int) int {    // 算一下因子里有多少个5就可以了,2有很多个就不用管了
    cnt := 0
    for n>=5 {
        cnt += n/5
        n /= 5
    }
    return cnt
}
```