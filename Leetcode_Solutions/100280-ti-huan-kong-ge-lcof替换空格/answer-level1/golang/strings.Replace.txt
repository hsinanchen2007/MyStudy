### 解题思路
使用strings提供的Replace函数进行替换，s为获取到的字符串，" "为替换前的字串，"%20"为替换后的字串，-1为一个N值，表示替换前N个字串，如果N<1则替换所有字串

### 代码

```golang
func replaceSpace(s string) string {
    return strings.Replace(s," ","%20",-1)
}
```