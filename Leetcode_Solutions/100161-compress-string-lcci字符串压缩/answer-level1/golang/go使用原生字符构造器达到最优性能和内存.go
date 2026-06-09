### 解题思路
整个程序都很简单，主要用字符构造器预先分配内存，减少内存多次分配，就能达到最优性能和内存

### 代码

```golang
func compressString(S string) string {
    length := len(S)
    if length == 0 {
        return S
    }
    //使用构造器
    var output strings.Builder
    //grow方法可以预先分配内存
    output.Grow(50000)
    var c = S[0] //相同字符
    var num int = 1 //字符重复次数
    //通过遍历，比较字符计算字符重复次数
    //当字符不相等时，将字符和重复次数写入output，并重置字符和次数，
    for i:=1; i<length; i++ {
        if c == S[i] {
            num++            
        }else {
            output.WriteString(string(c))
            output.WriteString(strconv.Itoa(num))
            num = 1
            c = S[i]
        }
    }
    //循环结束后，写入还未写入字符和重复次数
    output.WriteString(string(c))
    output.WriteString(strconv.Itoa(num))

    if output.Len() >= length {
        return S
    }
    return output.String()
}
```
![image.png](https://pic.leetcode-cn.com/2459ec9556934d7d5bb4562ea33eef879434f4a602012ecdafb53f2df71df2b1-image.png)

