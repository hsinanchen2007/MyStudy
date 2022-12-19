### 解题思路
遍历两次：  
- 第一次建表
- 第二次进行查找
### 代码

```golang
func firstUniqChar(s string) byte {
	res := make([]int, 26)
    //建表
	for _, si := range s {
		res[si - 'a']++
	}
    //按序查找
	for _, si := range s {
		if res[si - 'a'] == 1 {
			return byte(si)
		}
	}
	return ' '
}
```