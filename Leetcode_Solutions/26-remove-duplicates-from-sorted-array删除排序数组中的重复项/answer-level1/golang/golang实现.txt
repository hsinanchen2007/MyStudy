### 解题思路
刚开始想遇到重复的就把重复的删掉，即nums=append(nums[:i],nums[i+1:]...)，但是应该是这种方法有性能问题，遇到特别大的数组时会超时，（此外，由于删掉了一个数组元素，因此要记得i--）。
第二种思路是参考top2的题解，使用双指针，也叫快慢指针，直接用后面的元素覆盖前面的，这样耗时较少

### 代码
```
接法一
func removeDuplicates(nums []int) int {
	if len(nums)<=1{
		return len(nums)
	}
	//var  resLen int=1
	curCmpNum:=nums[0]
	for i:=1;i<len(nums) ;i++  {
		if nums[i]==curCmpNum {
			nums=append(nums[:i],nums[i+1:]...)
			i--
		}else {
			curCmpNum=nums[i]
		}
		fmt.Println("curCmpNum is ",curCmpNum,"num[i] is ",nums[i],"cur nums is",nums)
	}

	return len(nums)
}

```

```golang  接法二
func removeDuplicates(nums []int) int {
	if len(nums)<=1{
		return len(nums)
	}
    //双指针，快慢指针，可以参考题解的前两个的思路
	low:=0
    for high:=1;high<len(nums);high++{
        if nums[low]!=nums[high]{
            nums[low+1]=nums[high]
            low++
        }
    }

	return low+1
}

```

