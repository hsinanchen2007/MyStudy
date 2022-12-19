### 解题思路
此处撰写解题思路
这个 题目有歧义，真 浪费时间，什么叫 “并且 i 和 j 的差的绝对值最大为 k”，是说 i和j差的绝对值 要达到最大，并且这个值等于k，还是说i和j的差的绝对值 不能 超过k？？？
### 代码

```golang
func containsNearbyDuplicate(a []int, k int) bool {
	
	for i:=0;i<len(a);i++{
		for j:=i+1;j<= i+k&&j<len(a);j++{
			if a[i]==a[j]{
				return true
			}
		}
	}
	
	return false
}
```