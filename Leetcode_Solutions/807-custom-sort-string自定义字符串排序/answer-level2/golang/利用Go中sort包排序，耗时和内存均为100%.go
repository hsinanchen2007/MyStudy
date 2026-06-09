



思路： 自定义结构体并重写sort.Interface接口，str.Data为实际要进行排序的[]byte，将待排序转换为[]byte以便于进行操作，排序完再转换为string即可。
注意点：我猜有人可能会说，那在T中出现但是S中未出现的字符c怎么排序的嘞？这种情况下str.Sort[c]均为0，即顺序不变,map中索引未初始化的键其值为默认值而不会报错，delete删除未初始化的键也不报错，默认不动作，map特性哦~
```
// 对自定义类型进行排序，重写下面三个函数即可
type Str struct {
	Data []byte
	Sort map[byte]int
}
func (s Str) Len() int {
	return len(s.Data)
}

func (s Str) Less(i, j int) bool {
	return s.Sort[s.Data[i]] < s.Sort[s.Data[j]]
}

func (s Str) Swap(i, j int) {
	s.Data[i], s.Data[j] = s.Data[j], s.Data[i]
}

func customSortString(S string, T string) string {
	byteStr := []byte(S)
	input := []byte(T)

	var str = Str{
		Data: input,
		Sort: make(map[byte]int),
	}
	for i := 0; i < len(byteStr); i++ {
		str.Sort[byteStr[i]] = i
	}

	sort.Sort(str)
	return string(str.Data)
}
```