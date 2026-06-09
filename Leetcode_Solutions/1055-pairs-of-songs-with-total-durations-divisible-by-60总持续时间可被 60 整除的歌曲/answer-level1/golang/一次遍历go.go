### 解题思路
此处撰写解题思路

### 代码

```golang
func numPairsDivisibleBy60(time []int) int {
//因为除以60之后的余数是0-59之间，所以 新建一个长度为60的数组
	res:=make([]int,60)
	count:=0
	for _,v:=range time{
		v%=60
		var target int
		if v==0{
			target=0
		}else{
			target=60-v
		}
		count+=res[target]
		res[v]++
	}
	return count
}
```