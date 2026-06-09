### 解题思路
// 执行用时 :0 ms, 在所有 golang 提交中击败了100.00%的用户
//内存消耗 :5 MB, 在所有 golang 提交中击败了100.00%的用户

### 代码

```golang
func minDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }
    minD := math.MaxInt32
    curL := 0
    
    cur := root
    var mostRight *TreeNode
    
    for cur != nil {
        mostRight = cur.Left
        if mostRight != nil {//有左子树能来到两次
            //找到左边最右
            mostRightHeight := 1
            for mostRight.Right != nil && mostRight.Right != cur {
                mostRight = mostRight.Right
                mostRightHeight++
            }
            if mostRight.Right == nil {//第一次到
                curL++ // 更新为当前层
                mostRight.Right = cur
                cur = cur.Left
                continue
            } else {//第二次到
                mostRight.Right = nil
                if mostRight.Left == nil && curL < minD{
                    minD = curL
                } 
                //更新为当前层
                curL = curL - mostRightHeight
            }
        } else {//只能来到一次, 它是从父节点来的
            curL++ // 更新为当前的层
        }
        cur = cur.Right
    }
    
    rightHeight := 1
    for root.Right != nil {
        root = root.Right
        rightHeight++
    }
    if root.Left == nil && rightHeight < minD {
        minD = rightHeight
    }
    
    return minD
}
```