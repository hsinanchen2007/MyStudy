**思路**

```
剪枝思路：
    同层里面出现相同的，减掉。
```
**实现**


```
func helper(candidates []int,startIndex int,curSlice []int,result *[][]int,curNum int,target int)  {
	for i:=startIndex;i<len(candidates) ;i++  {
		if i!=startIndex && candidates[i] == candidates[i-1] {
			continue
		}
		if curNum+candidates[i] > target{
			break
		}else if curNum+candidates[i] == target{
			var tempSlice = make([]int,len(curSlice)+1)
			copy(tempSlice,curSlice)
			tempSlice[len(curSlice)] = candidates[i]
			*result = append(*result, tempSlice)
		}else{
			var tempSlice = make([]int,len(curSlice)+1)
			copy(tempSlice,curSlice)
			tempSlice[len(curSlice)] = candidates[i]
			helper(candidates,i+1,tempSlice,result,curNum+candidates[i],target)
		}
	}
}
func combinationSum2(candidates []int, target int) [][]int {
	sort.Ints(candidates)
	var result = make([][]int,0)
	helper(candidates,0,[]int{},&result,0,target)
	return result

}
```
