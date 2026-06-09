### 解题思路
此处撰写解题思路
1、数组nums转map字典映射，key和val互相颠倒
2、遍历循环数组nums
3、根据和target与数组nums当前元素相减的值tmpNum
4、根据相减的值tmpNum去map字典映射中查找是否有有定义
5、如果有定义，并且tmpNum不是其本身（防止nums[3,4,2],target=6）这种2n=target问题
4、则返回当前元素的key，和字典map的val（也就是最原始的key）

### 代码

```golang
func twoSum(nums []int, target int) []int {
	numMap:= make(map[int]int,len(nums))
	for k,num :=range nums{
		numMap[num]=k
	}

	for k,num :=range nums{
		tmpNum:= target-num
		if _,ok:=numMap[tmpNum];ok {
			if numMap[tmpNum]!=k{
				return []int{k,numMap[tmpNum]}
			}
		}
	}
	return []int{}
}
```