### 解题思路
1.将整个切片（数组）反转      7,6,5,4,3,2,1
2.反转前(k % 切片长度)个元素  5,6,7,4,3,2,1
3.反转后面的元素             5,6,7,1,2,3,4

### 代码

```golang
func rotate(nums []int, k int)  {
    reverse(nums)
    m := k % len(nums)
	reverse(nums[:m])
	reverse(nums[m:])
}
func reverse(s []int){
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
}
```