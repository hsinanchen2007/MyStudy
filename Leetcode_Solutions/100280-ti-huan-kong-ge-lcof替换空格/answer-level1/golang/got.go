### 解题思路
思路就是两个指针从后往前移动copy
时间o(n),空间o(1)

### 代码

```golang
func replaceSpace(s string) string {
    return strings.Replace(s," ","%20",-1)

}
```