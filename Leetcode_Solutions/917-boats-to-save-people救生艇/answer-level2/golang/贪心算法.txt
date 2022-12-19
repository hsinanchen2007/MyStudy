双指针注意边界情况处理

```


// 贪心算法： 最重的人先和最轻的人上船，超限则最重的人自己登船

func numRescueBoats(people []int, limit int) int {
	//sort.Sort(sort.IntSlice(people))
	sort.Ints(people)
	i, j := 0, len(people)-1
	sum := 0

	for i < j {
		if people[j] + people[i] <= limit {
			sum++
			i++
			j--
			continue
		}
		j--
		sum++
	}

    if i == j {
		sum++
	}

	return sum
}

```