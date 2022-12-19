### 解题思路

双循环，遇到索引和相同的就加进结果数组，若当前两个索引比之前的和小，则把结果数组清空，再添加当前字符串。

### 代码

```golang
func findRestaurant(list1 []string, list2 []string) []string {
	sum := len(list1) + len(list2)
	res := []string{}
	for i := 0;i < len(list1);i++ {
		for j := 0;j < len(list2);j++ {
			if list1[i] == list2[j] {
				if i + j < sum {
					sum = i + j
					res = []string{}
					res = append(res,list1[i])
				}else if i + j == sum {
					res = append(res,list1[i])
				}
			}
		}
	}
	return res
}
```