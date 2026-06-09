```
func arrayRankTransform(arr []int) []int {
    lenth := len(arr)
    var res = make([]int, lenth)
	copy(res, arr)
	sort.Ints(res)
	var index = 1
	
	var arrMap = make(map[int]int, 10)
	var ok bool
	for i := 0; i < lenth; i++ {
		_, ok = arrMap[res[i]]
		if !ok {
			arrMap[res[i]] = index
		}
        if i != lenth-1{
            if res[i] != res[i+1] {
                index++
            }
        }else{
            arrMap[res[lenth-1]] = index
        }
	}
	var res1 = make([]int, 0, 10)
	for i := 0; i < lenth; i++ {
		res1 = append(res1, arrMap[arr[i]])
	}
	return res1
}
```
