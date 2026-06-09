### 解题思路
利用ASCII码规则大写字母比小写字母小**32**，把范围为(64,91)的元素加32得到它的小写。

> 可通过命令查看ASCII码
>
> ```bash
> man ascii
> ```

### 代码

```golang
func toLowerCase(str string) string {
    var res []byte
    for _, v := range str {
        if v < 91 && v > 64 {
            v += 32
        }
        res = append(res, byte(v))
    }
    return string(res)
}
```