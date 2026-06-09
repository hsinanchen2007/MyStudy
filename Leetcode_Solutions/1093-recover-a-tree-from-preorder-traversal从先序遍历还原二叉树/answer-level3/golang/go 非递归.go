**方法**
1. 先处理深度, 再截取数字
2. 利用切片模拟入栈和出栈记录父节点的指针

**结果**
![image.png](https://pic.leetcode-cn.com/e0dc00c59c7dd8d13385d4be3450a9165afffe0c465dc90aa20fa9cb79a063e6-image.png)

**代码**
```
func recoverFromPreorder(S string) *TreeNode {

	l := len(S)
	if l == 0 {
		return nil
	}

	dummy := &TreeNode{}
	deepMap := make([]*TreeNode, 0)

	for pre, cur := 0, 0; cur < l; cur++ {

		if S[cur] != '-' {

			deep := cur - pre
			pre = cur

			for ; cur <= l; cur++ {

				//cur == l 防止最后一个数漏掉
				if cur == l || S[cur] == '-' {

					node := &TreeNode{}
					node.Val, _ = strconv.Atoi(S[pre:cur])

					if deep == 0 {
						dummy.Left = node
						deepMap = append(deepMap, node)
					} else {
						parent := deepMap[deep - 1]
						if parent.Left == nil {
							parent.Left = node
						} else {
							parent.Right = node
						}

						//更新栈
						deepMap = deepMap[:deep]
						deepMap = append(deepMap, node)
					}

					pre = cur
					break
				}
			}
		}
	}

	return dummy.Left
}
```


