比较标准的一道并查集的题目
大致分三步走：
1、查找函数的实现
2、合并集合
3、相同集合的元素进行排序

```
var parents = make([]int, 100001)

// 查找函数，并进行路径压缩
func find(a int) int {
	for a != parents[a] {
		parents[a] = parents[parents[a]]
		a = parents[a]
	}
	return a
}

func smallestStringWithSwaps(s string, pairs [][]int) string {
	var resultTemp []byte
	for i := 0; i < len(s); i++ {
		resultTemp = append(resultTemp, s[i])
	}

    // 初始化每个节点的父节点为自己
	for i := 0; i < len(s); i++ {
		parents[i] = i
	}

    // 合并集合
	for i := 0; i < len(pairs); i++ {
		parents[find(pairs[i][0])] = find(pairs[i][1])
	}

    // 用map存储相同父节点的数据
	circle := make(map[int][]int)
	for i := 0; i < len(s); i++ {
		temp := find(i)
		circle[temp] = append(circle[temp], i)
	}

    // 将相同父节点的数据进行排序

	for _, v := range circle {
		var temp []int
		for i := 0; i < len(v); i++ {
			temp = append(temp, int(s[v[i]]))
		}
		sort.Ints(temp)
		for i := 0; i < len(v); i++ {
			resultTemp[v[i]] = byte(temp[i])
		}
	}

	result := string(resultTemp)

	return result

}
```
