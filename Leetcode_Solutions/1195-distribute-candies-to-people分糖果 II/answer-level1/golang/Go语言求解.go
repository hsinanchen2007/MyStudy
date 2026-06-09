### 解题思路
暴力求解，也能双百

### 代码

```golang
func distributeCandies(candies int, num_people int) []int {
    ans:=make([]int,num_people)
	tmp:=0
	i:=0
	for{
		tmp++
		if tmp>candies{
			tmp=candies
		}
		ans[i%num_people]+=tmp
		candies-=tmp
		i++
		if candies==0{
			break
		}
	}
	return ans
}
```