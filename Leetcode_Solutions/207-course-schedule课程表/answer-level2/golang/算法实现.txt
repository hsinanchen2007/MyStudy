```
func canFinish(numCourses int, prerequisites [][]int) bool {
	var (
		// 计算入度
		int_num = make([]int, numCourses)
		// 存放入度为0
		queue = make([]int, 0, numCourses)
		// 最终结果
		res = make([]int, 0, numCourses)
	)
	// 计算入度
	for _, val := range prerequisites {
		int_num[val[0]]++
	}
	// 入度为0添加到队列中
	for i, val := range int_num {
		if val == 0 {
			queue = append(queue, i)
		}
	}

	for len(queue) != 0 {
		val := queue[0]
		queue = queue[1:]
		res = append(res, val)
		for _, loop_val := range prerequisites {
			// 搜索相邻的边，如果相等入度边就减少
			if loop_val[1] == val {
				int_num[loop_val[0]]--
				// 当入度边为0，就查找 loop_val[0] 的入度边
				if int_num[loop_val[0]] == 0 {
					queue = append(queue, loop_val[0])
				}
			}
		}
	}
	if len(res) == numCourses {
		return true
	} else {
		return false
	}
}
```
排序的原理前面大牛都讲过了，这里我记录一下 “入度” 为什么这样统计 （ps: 讲解的图都是从前面开始删除 “入度为0的边” ，然后代码又都是从后面开始删的）

1. 在该题中参数都是 "A -> B"，而我们又要不断删除 "入度为0" 的边，按道理应该是统计 "A" 是否有入度边的，但是从 "A" 入手的话我们就必须把 "B" 的情况也考虑进去，例：[0,1],[1,2],[2,3],[0,3]。

2. 而我们从 "B" 开始的话每删除一个 "B" 就代表从 "A->B" 删除一条 "A" 的出边，当出边为0时 "A" 就成了末尾元素，这样依次循环即可得到结果。所以说算法中统计 “入度” 在我看来应该是统计出边

