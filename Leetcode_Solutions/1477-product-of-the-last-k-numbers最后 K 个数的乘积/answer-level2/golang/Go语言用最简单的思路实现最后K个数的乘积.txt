```
type ProductOfNumbers struct {
    num []int
}


func Constructor() ProductOfNumbers {
    return ProductOfNumbers{
        num:make([]int,0,10),
	}
}


func (this *ProductOfNumbers) Add(num int)  {
    this.num = append(this.num, num)
}


func (this *ProductOfNumbers) GetProduct(k int) int {
	lenth := len(this.num)
	var res = 1
	for i:=lenth-1;i>= lenth - k;i--{
		res *= this.num[i]
	}
	return res
}
```
