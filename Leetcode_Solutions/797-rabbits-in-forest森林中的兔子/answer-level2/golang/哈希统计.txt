通过哈希统计出每个说法相同的兔子数量。
假设说除自己之外还有3个同颜色的兔子有7只，按最少计算的话，那么，3+1(自己)为分组大小。用7个来计算则有2组 7/4 天花板取整2*4 = 8只。
以此类推
```
func numRabbits(answers []int) int {
	hash := make(map[int]int)
	n := 0
	for _,v:=range answers{
		hash[v]++
	}
	for k,v:=range hash{
		k+=1
		n+=(v/k)*k
		if (v%k)>0{
			n+=k
		}
	}
	return n
}
```