### 解题思路
问题：在定义全局变量的时候，在本地结果是对的，但提交上去后，结果是错的
上网搜索了一下，说不能定义全局变量，按这个说法修改后提交，的确是对的，这是什么原因呢，哪位老大知道请告知一声

### 代码

```golang
type ElemNode struct {
	Next  map[int]*ElemNode
}

func InsertResultIntoTree(treeRoot *ElemNode, result []int) {
	thisNode := treeRoot
	for _, elemValue := range result {
		if _, exist := thisNode.Next[elemValue]; exist == false {
			thisNode.Next[elemValue] = &ElemNode{
				Next:make(map[int]*ElemNode),
			}
		}
		thisNode = thisNode.Next[elemValue]
	}
}

func BuildOutputResult(curRes []int, outResult *[][]int, curNode *ElemNode) {
	flag := 0
	for key, value := range curNode.Next {
		flag = 1
		newRes := make([]int, len(curRes)+1)
		copy(newRes, curRes[:len(curRes):len(curRes)])
		newRes[len(curRes)] = key

		BuildOutputResult(newRes, outResult, value)
	}

	if flag == 0 && len(curRes) > 0 {
		*outResult = append(*outResult, curRes)
	}
}

func GetCombine(treeRoot *ElemNode, candidates, thisRes []int, thisIdx, left int)  {
	if left == 0 {
		InsertResultIntoTree(treeRoot, thisRes)
		return
	}

	for i := thisIdx; i < len(candidates); i++ {
		value := candidates[i]
		if left < value { // 当前数小于剩余数时，不用再检查
			break
		}

		newRes := make([]int, len(thisRes)+1)
		copy(newRes, thisRes[:len(thisRes):len(thisRes)])
		newRes[len(thisRes)] = value
		GetCombine(treeRoot, candidates, newRes, i + 1, left - value)
	}
}

func BubbleSort(nums []int) {
	for i := 0; i < len(nums) - 1; i++ {
		for j := i; j < len(nums); j++ {
			if nums[i] > nums[j] {
				nums[i], nums[j] = nums[j], nums[i]
			}
		}
	}
}

func combinationSum2(candidates []int, target int) [][]int {
	BubbleSort(candidates)

	treeRoot := &ElemNode{
		Next:make(map[int]*ElemNode),
	}
	GetCombine(treeRoot, candidates, nil, 0, target)

	thisRes := make([]int, 0)
	outResult := make([][]int, 0)
	BuildOutputResult(thisRes, &outResult, treeRoot)

	return outResult
}
```