### 解题思路

排序的思想
- 首先将nums中的元素转换为string
- 然后利用自定义sort.Slice() 的比较函数，这里的比较函数为`ss[i]+ss[j] >= ss[j]+ss[i]`
- 最后将排完序的字符串打印出来。这里注意要将前面的`0`去除掉。

### 代码

```golang
func largestNumber(nums []int) string {
	ss := make([]string, len(nums))
	for i, num := range nums {
		ss[i] = strconv.Itoa(num)
	}
	sort.Slice(ss, func(i, j int) bool {
		return ss[i]+ss[j] >= ss[j]+ss[i]
	})
	o := strings.Join(ss, "")
	if o[0] == '0' {
		return "0"
	}
	return o
}
```