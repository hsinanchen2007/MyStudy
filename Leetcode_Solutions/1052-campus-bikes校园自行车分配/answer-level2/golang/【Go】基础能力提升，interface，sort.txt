```
type ManhattanInfo struct {
	 worker int
	 bike int
	 manhattan int
}

type ManhattanInfoArray []ManhattanInfo

func (a ManhattanInfoArray)Len() int {
	return len(a)
}

func (a ManhattanInfoArray)Less(i, j int) bool{
	left := a[i]
	right := a[j]
	if left.manhattan == right.manhattan {
		if left.worker == right.worker {
			return left.bike < right.bike
		}
		return  left.worker < right.worker
	}
	return left.manhattan < right.manhattan
}

func (a ManhattanInfoArray)Swap(i, j int) {
	a[i], a[j] = a[j], a[i]
}

func assignBikes(workers [][]int, bikes [][]int) []int {
	workerVisited := make([]bool, len(workers))
	bikeVisited := make([]bool, len(bikes))

	result := make([]int, len(workers))
	manhattanInfoArray := make([]ManhattanInfo, 0)
	for worker, workerPosition := range workers {
		for bike, bikePosition := range bikes {
			var manhattanInfo ManhattanInfo
			manhattanInfo.worker = worker
			manhattanInfo.bike = bike
			manhattanInfo.manhattan = int(math.Abs(float64(workerPosition[0] - bikePosition[0])) + math.Abs(float64(workerPosition[1] - bikePosition[1])))
			manhattanInfoArray = append(manhattanInfoArray, manhattanInfo)
		}
	}
	sort.Sort(ManhattanInfoArray(manhattanInfoArray))

	for _, manhattanInfo := range manhattanInfoArray {
		if bikeVisited[manhattanInfo.bike] || workerVisited[manhattanInfo.worker] {
			continue
		}
		result[manhattanInfo.worker] = manhattanInfo.bike
		workerVisited[manhattanInfo.worker] = true
		bikeVisited[manhattanInfo.bike] = true
	}
	return result
}
```
