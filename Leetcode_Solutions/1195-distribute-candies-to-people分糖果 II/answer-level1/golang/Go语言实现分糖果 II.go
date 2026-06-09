![Snipaste_2020-03-05_09-01-07.png](https://pic.leetcode-cn.com/9d3421e30529296761b437e5c4674a3cb36038390d4c28c9e666ce53a6ba4d9a-Snipaste_2020-03-05_09-01-07.png)

```
func distributeCandies(candies int, num_people int) []int {
    var res = make([]int, num_people)
	var sum = 0
	var flag = false
	for {
		if flag {
			break
		}
		for i := 0; i < num_people; i++ {
			sum++
			if sum >= candies {
				sum = candies
				flag = true
			}
			res[i] += sum
			candies -= sum
			if flag {
				break
			}
		}
	}
	return res
}
```
