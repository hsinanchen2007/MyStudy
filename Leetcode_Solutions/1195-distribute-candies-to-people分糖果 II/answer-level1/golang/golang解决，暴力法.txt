golang解决，暴力法

github: [https://github.com/Crownt/leetcode](https://github.com/Crownt/leetcode)


```
// 暴力法
// 时间复杂度：O(sqr(G))  空间复杂度：O(1)  其中，G为糖果数目，s<=sqr(2G)

func distributeCandies(candies int, num_people int) []int {
	
	people := make([]int, num_people)
	i := 0
	for candies>0 {
		if candies>i+1 {
			people[i%num_people] += (i+1)
			candies -= (i+1)
		} else {
			people[i%num_people] += candies
			candies -= candies
		}
		i++
	} 

	return people
}
```
