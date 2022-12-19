### 解题思路
先对数组进行排序，方便后续处理。
遍历一遍找到最小和最大索引。最后要注意处理一些特殊情况， beginIndex==-1{//没找到以及endIndex==len(nums)。最后删除这几个元素即可nums=append(nums[:beginIndex],nums[endIndex+1:]...)。

### 代码

```golang
func removeElement(nums []int, val int) int {
    if len(nums)==0{
        return 0
    }
	sort.Ints(nums)//先排个序，方便处理
	beginIndex,endIndex:=-1,-1
	for i:=0;i<len(nums) ;i++  {
		if nums[i]==val {
			if beginIndex == -1{
				beginIndex=i
                endIndex=i
			}else {//不止一个
				endIndex=i
			}
		}
	}
    if beginIndex==-1{//没找到
        return len(nums)
    }
    if endIndex==len(nums){//val是最大的，不能执行nums=append(nums[:beginIndex],nums[endIndex+1:]...)，因为endIndex+1会越界
        return beginIndex
    }
	nums=append(nums[:beginIndex],nums[endIndex+1:]...)
	return len(nums)
}

```