```
import "sort"

type Elem5329 struct {
	Val   int
	Count int
}

func minSetSize(arr []int) int {
	var (
		i        int
		length   = len(arr)
		valCount = map[int]int{}
	)
	for i = 0; i < length; i++ {
		valCount[arr[i]]++
	}

	var valArray = make([]Elem5329, len(valCount))
	for k, v := range valCount {
		valArray = append(valArray, Elem5329{
			Val:   k,
			Count: v,
		})
	}

	sort.Slice(valArray, func(i, j int) bool {
		return valArray[i].Count > valArray[j].Count
	})

	currCount := 0
	currSum := 0
	for i = 0; i < len(valArray); i++ {
		currCount++
		currSum += valArray[i].Count
		if currSum*2 >= length {
			return currCount
		}
	}
	return length
}

```
