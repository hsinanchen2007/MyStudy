[MojoTech Golang](https://mojotv.cn/)
![微信截图_20200113132345.png](https://pic.leetcode-cn.com/3c46849790c70feedcb948733ecc094fd1c53b255b35d345eaac344b5bacf75f-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200113132345.png)

### 检查 A+ A字符拼接是否包含B
检查 A+ A字符拼接是否包含B

### 代码

```golang
func rotateString(A string, B string) bool {
    if len(A) != len(B){
        return false
    }
    return strings.Contains(A+A,B)
    
}
```