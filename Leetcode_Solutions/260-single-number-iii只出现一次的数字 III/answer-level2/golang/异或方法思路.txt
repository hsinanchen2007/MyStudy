**异或**
```
1.通过所有数据的异或resultNum--->单个出现异或结果集
2.设置标志位diff----->用于区分两个单体数据
3.求出一个单体数据x---->再用x^resultNum求出另一个
```
**代码**
```
func singleNumber(nums []int) []int {

	var resultNum int
	for i:=0;i<len(nums) ;i++  {
		resultNum = resultNum^nums[i]
	}
	var diff = resultNum&(-resultNum)
	var x int
	for i:=0;i<len(nums) ;i++  {
		if diff&nums[i]!=0{
			x = x^nums[i]
		}
	}
	return []int{x,x^resultNum}
}
```
