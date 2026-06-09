### 解题思路
[约瑟夫环](https://blog.csdn.net/u011500062/article/details/72855826)
### 代码

```golang
func lastRemaining(n int, m int) int {
    flag := 0
    for i := 2; i <= n; i++{
        flag = (flag + m) % i
    }
    return flag
}
```