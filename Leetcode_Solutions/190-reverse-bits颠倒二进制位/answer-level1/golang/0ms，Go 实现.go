
![image.png](https://pic.leetcode-cn.com/1ad6d6a7b3d42b143f395e1a812e5d401391a815bb9cf267b48abd5e4c19158e-image.png)

进制翻转
```
func reverseBits(num uint32) uint32 {
    var ans uint32 = 0
    t := 32
    for t>0 {
        ans <<= 1
        ans |= num%2
        num >>= 1
        t--
    }
    return ans
}
```