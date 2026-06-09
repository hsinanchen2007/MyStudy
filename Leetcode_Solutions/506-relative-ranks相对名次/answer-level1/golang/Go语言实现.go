func findRelativeRanks(nums []int) []string {

	var orders = make(map[int]int, 0)
	var length = len(nums)

	for i := 0; i < length; i++ {
		orders[i+1] = nums[i]
	}
	sort.Ints(nums)

	answer := make([]string, length)
	var order = 1
	var gmap = mapConvert(orders)
	for i := length - 1; i >= 0; i-- {
		//var key = getValueMap(orders, nums[i]) - 1
		var key = gmap[nums[i]] - 1
		switch order {
		case 1:
			answer[key] = "Gold Medal"
			break
		case 2:
			answer[key] = "Silver Medal"
			break
		case 3:
			answer[key] = "Bronze Medal"
			break
		default:
			answer[key] = strconv.Itoa(order)
		}
		order++
	}

	var answers = make([]string, 0)
	for i := 0; i < length; i++ {
		answers = append(answers, answer[i])
	}

	return answers
}


func mapConvert(gmap map[int]int) map[int]int {
	gmap1 := make(map[int]int, 0)
	for k, v := range gmap {
		gmap1[v] = k
	}
	return gmap1
}
