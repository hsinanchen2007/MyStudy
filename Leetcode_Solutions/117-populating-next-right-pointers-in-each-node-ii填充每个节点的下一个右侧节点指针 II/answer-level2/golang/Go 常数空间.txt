# bfs
1. `广度遍历` 使用队列，是为了保存上下文，才可找到 `下层遍历顺序`
2. 但是因为我们设置了Next,我们可以自然而然的从`父节点`获取到`下层遍历顺序`，所以完全可以抛弃 `Queue`
3. 只要思路对了，剩下的就是堆业务逻辑了


```golang
func connect(root *Node) *Node {
	if root == nil {
		return nil
	}

	cur := root //指针
	for cur != nil {
		var pre *Node  //前置节点
		var down *Node //下降节点，节点为下一层的左边第一节点
		for cur != nil {
			if cur.Left != nil { //左节点判断
				if pre != nil {
					pre.Next = cur.Left //pre不为空 设置Next
				} else {
					down = cur.Left //pre为空 设置下降节点
				}
				pre = cur.Left //设置前置节点
			}

			if cur.Right != nil { //右节点判断，同上
				if pre != nil {
					pre.Next = cur.Right
				} else {
					down = cur.Right
				}
				pre = cur.Right
			}
			cur = cur.Next //同层移动
		}
		cur = down //下降
	}
	return root
}
```

[Go版本 Github](https://github.com/temporaries/leetcode)
[对应模板 Github](https://github.com/temporaries/leetcode/blob/master/templates/tree/bfs.go)