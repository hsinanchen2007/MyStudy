### 解题思路

双循环，i代表小时，j代表分钟，数一下i和j二进制形式中1的个数，如果和num一样，则为当前num可以表示的时间。

### 代码

```golang
func readBinaryWatch(num int) []string {
	result := []string{}
	for i := 0;i < 12;i++ {
		for j := 0;j < 60;j++ {
			b1 := fmt.Sprintf("%b",i)
			b2 := fmt.Sprintf("%b",j)
			sumOne := strings.Count(b1,"1") + strings.Count(b2,"1")
			if sumOne == num {
				result = append(result,fmt.Sprintf("%d:%02d",i,j))
			}

		}
	}
	return result
}
```