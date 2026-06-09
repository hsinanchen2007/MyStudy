执行用时 :0 ms, 在所有 Go 提交中击败了100.00%的用户
内存消耗 :2.1 MB, 在所有 Go 提交中击败了61.20%的用户

三指针，因为这题也没有看题解就自己写出来了，所以还是蛮开心的
概括思路就是，碰见2就往后放，碰见0就往前放，但具体怎么放呢？还是看代码吧

```
func sortColors(nums []int)  {
	if len(nums)==0 {
		return
	}
	//碰见2就往后放
	//碰见0就往前放
	i,j:=0,len(nums)-1
	temp:=0
	for temp<len(nums){
		if nums[temp]==2&&temp<j{
			if nums[j]!=2 {
				nums[j],nums[temp]=nums[temp],nums[j]
			}else{
				j--
			}
		}else if nums[temp]==0&&temp>i{
			if nums[i]!=0 {
				nums[i],nums[temp]=nums[temp],nums[i]
			}else{
				i++
			}
		}else {
			temp++
		}
	}
}
```
