### 解题思路
此处撰写解题思路

### 代码

```golang
func diStringMatch(S string) []int {
	N:= len(S)
	//nums:=make([]int,0)
	min:=0
    max:=N
	str:=[]rune(S)
	res:=make([]int,0)
	for i:=0;i< len(str);i++{
        //当 I的时候放 最小值，D的时候放最大值即可
		if str[i]=='I'{
			res= append(res, min)
			min++
		}else{
			res= append(res, max)
			max--
		}
	}
    //最后min=max
	res= append(res, min)
	return res
}
```