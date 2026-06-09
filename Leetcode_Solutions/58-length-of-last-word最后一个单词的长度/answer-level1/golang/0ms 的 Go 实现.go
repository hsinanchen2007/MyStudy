![image.png](https://pic.leetcode-cn.com/5d7ba5c127685e080b863c2b3e03bc2cfb37166c09f653b6f99234c523aa8b2d-image.png)

注意输入字符串前后可能会有多余空格，可以用 strip 或者 trim 先清理一下。

代码：
```
func lengthOfLastWord(s string) int {
    s = strings.Trim(s, " ")
    str_list := strings.Split(s, " ")
    if len(str_list) == 0 {
        return 0
    } else {
        return len(str_list[len(str_list)-1])
    }
}
```

经评论区大佬提醒，Golang 中 Trim() 和 Split() 这两句话的功能可以用 Fields() 代替，修改后代码如下：
```
func lengthOfLastWord(s string) int {
    str_list := strings.Fields(s)
    if len(str_list) == 0 {
        return 0
    } else {
        return len(str_list[len(str_list)-1])
    }
}
```