参考hlxing大佬的思路
```
// 并查集
func makeConnected(n int, connections [][]int) int {
	father := make([]int, n)  // 保存并集树father节点的值
	high := make([]int, n) // 保存father节点树的高度
	for i:=0; i<n; i++ {
		father[i] = i // 默认自己
		high[i] = 1  // 默认高度1
	}

	num := n // 合并后的节点数量
	cnt := 0 // 多余线缆数量
	// 查找树的father节点的值
	var find func(p int) int
	find = func(p int) int {  // 压缩路径：加快速度
		if father[p] != p {
			father[p] = find(father[p])
		}
		return father[p]
	}

	union := func(f, t int) {
		if high[f] < high[t] {  // 加权：小树合并到大树，减少树的高度。find的次数
			father[f] = t
			high[t] += high[f]
		} else {
			father[t] = f
			high[f] += high[t]
		}
	}

	// 根据connections 合并节点
	for i:=0; i<len(connections); i++ {
		a, b := connections[i][0], connections[i][1]
		f, t := find(a), find(b)
		if f == t {
			cnt++
			continue
		}
		// 合并节点
		union(f, t)
		num--
	}

	if num-1 > cnt {
		return -1
	} else {
		return num-1
	}
}
```
