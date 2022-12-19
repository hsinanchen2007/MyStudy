### 解题思路
此处撰写解题思路
遇到字符串问题，首先脑袋map里找到双指针这个思路，不行的话再寻思别的办法
### 代码

```golang
func reverseString(s []byte)  {
    if len(s) != 0 || len(s) != 1 {
        high := len(s) - 1
        for i := 0; i < len(s) / 2; i++ {
            s[i], s[high] = s[high], s[i]
            high--
        }
    }
}
```