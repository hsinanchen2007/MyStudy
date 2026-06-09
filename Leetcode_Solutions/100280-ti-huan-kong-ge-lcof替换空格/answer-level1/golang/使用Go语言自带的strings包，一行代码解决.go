### 解题思路

替换字符串，直接用`strings.Replace`解决。  
第一个参数为源字符串，第二个参数表示被替换的部分，第三个参数表示最终被替换成的值，第四个参数表示替换的次数，-1表示不限制次数。  

### 代码

```golang
func replaceSpace(s string) string {
    return strings.Replace(s, " ", "%20", -1)
}
```