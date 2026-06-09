### 解题思路
1. 使用 strings.Split 切分以空格隔开原字符串为一个字符串数组
2. 中间加上 %20 又链接起来

或者使用同功能函数
`func Replace(s, old, new string, n int) string`
s 为源字符串
old 为需要替换的字符串
new 为替换目标
n 代表替换多少次. -1 代表 all 
返回值 为替换之后的 字符串

### 代码

```golang
func replaceSpace(s string) string {
    // new := strings.Split(s, " ")
    // var x = ""
    // for i, v := range new{
    //     if i != len(new) && i != 0{
    //         x += "%20"
    //     }
    //     x += v
    // }
    // return x 
    return  strings.Replace(s, " ", "%20",-1)
}
```