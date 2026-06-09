### 解题思路

#### 方法1.直接调用库函数

### 代码

```golang
func countSegments(s string) int {
	count := strings.Fields(s)
	return len(count)
}
```
#### 方法2.遍历字符串，若当前下标之前为空格（或者为初始下标），且自身不为空格，则其为单词开始的下标。

### 代码

```golang
func countSegments(s string) int {
	var count int = 0
	for i := 0;i < len(s);i++ {
		if (i == 0 || s[i-1] == ' ') && s[i] != ' ' {
			count++
		}
	}
	return count
}
```