### 解题思路

也不叫没有递归吧，中间很多计算结果是可以重复利用的

### 代码

```golang
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

var (
    // n -> start -> nodes
    numTrees = map[int]map[int][]*TreeNode{}
)

func generateTrees1(n int, start int) []*TreeNode {
    if v1, ok1 := numTrees[n]; ok1 {
        if v2, ok2 := v1[start]; ok2 {
            return v2
        }
    }

    l := []*TreeNode{}
    if n == 1 {
        l = []*TreeNode{&TreeNode{start, nil, nil}}
    } else {
        for i := 1; i <= n; i++ {
            left_trees := []*TreeNode{}
            if v1, ok1 := numTrees[i-1]; ok1 {
                if v2, ok2 := v1[start]; ok2 {
                    left_trees = v2
                }
            }
            if len(left_trees) == 0 {
                left_trees = generateTrees1(i-1, start)
            }

            right_trees := []*TreeNode{}
            if v1, ok1 := numTrees[n-i]; ok1 {
                if v2, ok2 := v1[start+i]; ok2 {
                    right_trees = v2
                }
            }
            if len(right_trees) == 0 {
                right_trees = generateTrees1(n-i, start + i)
            }

            // make tree
            root_val := start + i - 1
            if len(left_trees) > 0 && len(right_trees) > 0 {
                for _, left_tree := range left_trees {
                    for _, right_tree := range right_trees {
                        root := &TreeNode{root_val, left_tree, right_tree}
                        l = append(l, root)
                    }
                }
            } else if len(left_trees) == 0 && len(right_trees) != 0 {
                for _, right_tree := range right_trees {
                    root := &TreeNode{root_val, nil, right_tree}
                    l = append(l, root)
                }
            } else if len(right_trees) == 0 && len(left_trees) != 0 {
                for _, left_tree := range left_trees {
                    root := &TreeNode{root_val, left_tree, nil}
                    l = append(l, root)
                }
            } else {
                root := &TreeNode{root_val, nil, nil}
                l = append(l, root)
            }
        }
    }
    if _, ok1 := numTrees[n]; ok1 {
        numTrees[n][start] = l
    } else {
        numTrees[n] = map[int][]*TreeNode{
            start: l,
        }
    }
    return l
}

func generateTrees(n int) []*TreeNode {
    return generateTrees1(n, 1)
}
```