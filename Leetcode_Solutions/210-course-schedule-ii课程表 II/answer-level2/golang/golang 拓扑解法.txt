func findOrder(numCourses int, prerequisites [][]int) []int {
	intcount := make([]int, numCourses)
	for _, edge := range prerequisites {
		intcount[edge[0]]++
	}
	queue := []int{}//用切片实现队列结构
	for i, val := range intcount {
		if val == 0 {
			queue = append(queue, i)
		}
	}
	order := []int{}
	for len(queue) != 0 {
		numCourses--
		tmp := queue[0]
		order = append(order, tmp)
		queue = queue[1:]//出队操作
		for _, edge := range prerequisites {
			if edge[1] == tmp {
				intcount[edge[0]]--
				if intcount[edge[0]] == 0 {
					queue = append(queue, edge[0])
				}
			}
		}
	}
//判断拓扑结构中是否出现了环
	if numCourses != 0 {
		return []int{}
	}
	return order
}
