本题的难点在于要知道第几次调用getBill函数，因而在结构体中存一个第几次调用的变量，每次调用的时候+1;还有就是商品列表那个序号其实是无序的，不一定是升序排列的数组，所以建议使用map将商品列表与价格对应起来，这样计算价格的时候更方便
```
type Cashier struct {
	num       int
	cousNum   int
	disciunt  int
	pricesMap map[int]int
}

func Constructor(n int, discount int, products []int, prices []int) Cashier {
	var res = Cashier{
		num:       n,
		cousNum:   0,
		disciunt:  discount,
		pricesMap: make(map[int]int, 10),
	}
	lenth := len(products)
	for i := 0; i < lenth; i++ {
		res.pricesMap[products[i]] = prices[i]
	}
	return res
}

func (this *Cashier) GetBill(product []int, amount []int) float64 {
	lenth := len(product)
	var sum = 0
	for i := 0; i < lenth; i++ {
		sum += amount[i] * this.pricesMap[product[i]]
	}
	var res float64
	this.cousNum++
	if this.cousNum%this.num == 0 {
		res = float64(sum) * float64(100-this.disciunt) / 100
	} else {
		res = float64(sum)
	}
	return res
}
```
