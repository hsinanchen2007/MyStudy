这题不限于英文字符，所以需要注意下，不能只用52位数组来记录相应的元素

```golang
type mats [][]int
func (s mats) Len() int           { return len(s) }
func (s mats) Less(i, j int) bool { return s[i][1] > s[j][1] }
func (s mats) Swap(i, j int)      { s[i], s[j] = s[j], s[i] }

func frequencySort(s string) string {
	var res strings.Builder
	mp:=make(map[int]int)
	for _,v:=range s{
		mp[int(v-' ')]++
	}
	var arr [][]int
	for k,v:=range mp{
		arr=append(arr,[]int{k,v})
	}
	sort.Sort(mats(arr))
	for i:=0;i<len(arr);i++{
		if arr[i][1]==0{
			break
		}
		for j:=0;j<arr[i][1];j++{
			res.WriteByte(byte(' '+arr[i][0]))
		}
	}
	return res.String()
}
```