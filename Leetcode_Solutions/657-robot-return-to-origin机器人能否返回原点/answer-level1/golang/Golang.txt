题解
```
func judgeCircle(moves string) bool {
    up, left := 0, 0
    for _, v := range moves {
        if v == 85 {
            up ++
        } else if v == 68 {
            up--
        } else if v == 76 {
            left++
        } else {
            left--
        }
    }
    return up == 0 && left == 0
}
```
提交
![image.png](https://pic.leetcode-cn.com/984ad910ae43414e1c7cc930bf38af8ae2ee9e6bae61b4ae477e53e070a3d12d-image.png)
