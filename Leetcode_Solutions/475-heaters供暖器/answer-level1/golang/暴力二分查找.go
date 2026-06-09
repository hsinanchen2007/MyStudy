就是暴力，我还以为有什么好做法呢，想了几个小时，翻了答案，原来就是暴力，二分暴力也是暴力

Your runtime beats 95.83 % of golang submissions
Your memory usage beats 86.67 % of golang submissions (6.5 MB)

```
func findRadius(houses []int, heaters []int) int {
	sort.Ints(heaters)
	minDistanceMax := 0
	for _, house := range houses {
		minDistance := findMinDistance(heaters, house)
		if minDistance > minDistanceMax {
			minDistanceMax = minDistance
		}
	}

	return minDistanceMax
}

func findMinDistance(heaters []int, target int) int {
	if target <= heaters[0] {
		return heaters[0] - target
	} else if target > heaters[len(heaters) - 1] {
		return target - heaters[len(heaters) - 1]
	} else {
		front := heaters[len(heaters) / 2 - 1]
		end := heaters[len(heaters) / 2 ]

		if front <= target && end >= target {
			if target - front > end - target {
				return end - target
			} else {
				return target - front
			}
		} else if target < front {
			return findMinDistance(heaters[:len(heaters) / 2], target)
		} else {
			return findMinDistance(heaters[len(heaters) / 2:], target)
		}
	}
}
```
