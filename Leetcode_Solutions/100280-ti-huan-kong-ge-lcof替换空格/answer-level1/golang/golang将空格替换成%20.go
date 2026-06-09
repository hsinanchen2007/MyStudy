### 解题思路
看到这个，首先想到的是url编码，一行代码url.PathEscape(),执行没问题，因为输入字符串直有空格会被编码，可如果出现url会编码的，就完蛋了。这时候就想到使用strings下的split的方法，分割成数组，再用join对数组进行拼接，ok完成

### 代码

```golang
func replaceSpace(s string) string {
 strSlice:=strings.Split(s," ")
 newStr:= strings.Join(strSlice,"%20")
 return newStr
}
```