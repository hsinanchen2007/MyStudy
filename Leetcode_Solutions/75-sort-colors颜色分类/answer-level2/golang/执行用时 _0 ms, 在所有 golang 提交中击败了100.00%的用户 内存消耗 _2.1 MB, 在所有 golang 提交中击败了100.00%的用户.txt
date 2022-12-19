### 解题思路
此处撰写解题思路
1. 因为数据有3种，所以想到了3路快速排序。
2. 设置临时变量**lt，gt**分别记录0的末位置和2的头位置
3. 如果**v==2 **将这个位置的数据交换到 2的头位置，因为gt设置的是闭区间，所有先减去1.
4. 如果是其它将目前第**i**个位置的值交换到lt，如果当前位置的数据是0，lt往前移动
### 代码

```golang
func sortColors(nums []int)  {
    n := len(nums)
	//[lt...gt) 
	lt := 0
	gt := n
	i := lt
	for i < gt {
		v := nums[i]
		if v == 2 {
			gt--
			nums[gt], nums[i] = nums[i], nums[gt]
		} else {
			nums[lt], nums[i] = nums[i], nums[lt]
			i++
			if v == 0 {
				lt++
			}
		}
	}
	return
}
```