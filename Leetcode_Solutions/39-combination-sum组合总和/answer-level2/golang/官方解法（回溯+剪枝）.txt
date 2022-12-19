**思路**
```
1. 排序。方便剪枝
2. 构造递归函数。 helper(result *[][]int,tempSlice []int,candidates []int,startIndex int,target int)
    result:结果集
    tempSlice:当前slice集合
    startIndex：下次地轨开始的下标。不遍历-去重
```
**代码**

```
func helper(result *[][]int,tempSlice []int,candidates []int,startIndex int,target int)  {
	if target==0{
		*result = append(*result, tempSlice)
		return
	}else{
		for i:=startIndex;i<len(candidates) ;i++  {
			if target - candidates[i] >= 0{
				var newTempSlice = make([]int,len(tempSlice)+1)
				copy(newTempSlice,tempSlice)
				newTempSlice[len(tempSlice)] = candidates[i]
				helper(result,newTempSlice,candidates,i,target-candidates[i])
			}{
				break
			}
		}
	}
}

func combinationSum(candidates []int, target int) [][]int {
	var result = make([][]int,0)
	sort.Ints(candidates)
	helper(&result,[]int{},candidates,0,target)
	return result
}
```
