如果houses 和 heaters 都 已经排好序了 。那么  一个house 的 前加热器一定是大于 等于 前一个 house 的前加热器，一个house 的后加热器 一定大于 前加热器 +1 （相等的情况不用考虑都为0）。用这样的思路 复杂度应该可以 O(n+m) 。用二分查找的优势在于 不用对 houses 进行排序可以省下一大部分时间。如果houses 数据 本来就是 排好序的，个人认为线性遍历会更好。用go 最好战绩 68ms 100%



```
func findRadius(houses []int, heaters []int) int {
	sort.Ints(houses)
	sort.Ints(heaters)


	preHeaderIndex := 0
	preDistance := -1
	preOk := false
	tempPreHeaderIndex := 0


	nextDistance := -1

	houseIndex := 0

	maxHeaterIndex := len(heaters) - 1
	maxHouseIndex := len(houses) - 1

	curDistance := 0
	final := 0
	preHeater := heaters[tempPreHeaderIndex]
	house := houses[houseIndex]
	shoudnext :=true

	for true {
		if !preOk {
			if preHeater < house {
				preHeaderIndex = tempPreHeaderIndex
				distance := house - preHeater
				if preDistance == -1 {
					preDistance = distance
				}else {
					if preDistance >= distance {
						preDistance = distance
					}
				}
				if tempPreHeaderIndex < maxHeaterIndex {
					tempPreHeaderIndex ++
					preHeater = heaters[tempPreHeaderIndex]
				}else {
					preOk = true
				}
			}else if preHeater == house {
				preDistance = 0
				preOk = true
				preHeaderIndex = tempPreHeaderIndex
			}else  {
				preOk = true
			}
		}


		if preOk && shoudnext {
			if preDistance == 0 {
				nextDistance = 0
			}else  if preDistance == -1 {
				nextDistance = heaters[preHeaderIndex] - house
			}else {
				if preHeaderIndex < maxHeaterIndex{
					nextDistance = heaters[preHeaderIndex +1] - house
				}else {
					shoudnext = false
				}
			}
		}

		if  preOk {
			if nextDistance != -1 && preDistance != -1 {
				if nextDistance < preDistance {
					curDistance = nextDistance
				}else {
					curDistance = preDistance
				}

			}else {
				if nextDistance == -1{
					curDistance = preDistance
				}else {
					curDistance = nextDistance
				}
			}

			if curDistance > final {
				final = curDistance
			}

			if houseIndex < maxHouseIndex {
				houseIndex ++
				house = houses[houseIndex]
			}else {
				break
			}
			if tempPreHeaderIndex != preHeaderIndex{
				preHeater = heaters[preHeaderIndex]
				tempPreHeaderIndex = preHeaderIndex
			}

			nextDistance = -1
			preOk = false
			preDistance = -1
		}

	}

	return final
}
```
