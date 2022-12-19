```
import (
	"math"
	"math/big"
	"sort"

)

type Elem5330 struct {
	Val *big.Int    // 这里其实用 int 就可以了，不用那么麻烦
}

func maxProduct(root *TreeNode) int {
	if root == nil {
		return 0
	}
	var array []Elem5330
	totalSum := sumTree(root, &array)
	sort.Slice(array, func(i, j int) bool {
		return array[i].Val.Cmp(array[j].Val) < 0
	})

	var (
		length   = len(array)
		other1   = big.NewInt(0)
		totalInt = big.NewInt(int64(totalSum))
	)
	i := 0
	diff := math.MaxInt32
	idx := 0
	target := big.NewInt(2)
    // 找到最接近 sum/2 的数就是答案了
	for i = 0; i < length; i++ {
		other1.Mul(array[i].Val, target)
		other1.Sub(totalInt, other1)
		val := int(other1.Abs(other1).Int64())
		if val < diff {
			idx = i
			diff = val
		}
	}

	other1.Sub(totalInt, array[idx].Val)
	other1.Mul(other1, array[idx].Val)
	other1.Mod(other1, big.NewInt(int64(1000000007)))
	return int(other1.Int64())
}

func sumTree(root *TreeNode, array *[]Elem5330) int {
	var (
		left, right int
	)
	if root.Left != nil {
		left = sumTree(root.Left, array)
	}
	if root.Right != nil {
		right = sumTree(root.Right, array)
	}

	root.Val = left + right + root.Val
	*array = append(*array, Elem5330{
		Val: big.NewInt(int64(root.Val)),
	})
	return root.Val
}

```
