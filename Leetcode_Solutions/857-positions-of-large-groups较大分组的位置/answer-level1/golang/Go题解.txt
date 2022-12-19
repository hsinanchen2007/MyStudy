简单的双指针，没什么技术含量
```golang
func largeGroupPositions(S string) [][]int {
    var res [][]int
	i,j:=0,0
	for i<len(S)-2&&j<len(S){
		if S[j]==S[i] {
			j++
		}else{
			if j-i>2 {
				res=append(res, []int{i,j-1})
			}
			i=j
		}
	}
    if j==len(S) {
		if j-i>2 {
			res= append(res, []int{i,j-1})
		}
	}
	return res

}
```