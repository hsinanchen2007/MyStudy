```
type StockSpanner struct {
	DecreaseList [][]int
}

func Constructor() StockSpanner{
	return StockSpanner{
		DecreaseList: make([][]int, 0),
	}
}

func (this *StockSpanner) Next (price int) int{
	if len(this.DecreaseList) == 0 {
		newItem := []int{price, 1}
		this.DecreaseList = append(this.DecreaseList, newItem)
	} else {
		var idx int
		count := 1
		for idx = len(this.DecreaseList) - 1; idx >= 0 && this.DecreaseList[idx][0] <= price; idx -= 1{
			count += this.DecreaseList[idx][1]
		}
		this.DecreaseList = append(this.DecreaseList[:idx+1], this.DecreaseList[len(this.DecreaseList):]...)
		newItem := []int{price, count}
		this.DecreaseList = append(this.DecreaseList, newItem)
	}
	return this.DecreaseList[len(this.DecreaseList)-1][1]
}
```