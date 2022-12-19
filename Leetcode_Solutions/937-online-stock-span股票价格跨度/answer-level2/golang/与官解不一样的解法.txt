1. 后来者使用前继的统计信息为基础，不需要统计所有过去每一天的数据；
2. 前一天的股票价格与今天股票比较，如果小于或等于今天股票，那么累加前一天的spanner，然后跳跃过前一天的spanner，这个区间前一天已经都统计过；
2. 使用数组保存每一天股票价格和spanner，方便后继统计时进行跳跃过不需要再统计的区间；

```golang
type StockSpanner struct {
    prices []*Spanner
    count int
}

type Spanner struct {
    price int
    spanner int
}


func Constructor() StockSpanner {
    return StockSpanner {
        prices: []*Spanner{},
    }
}


func (this *StockSpanner) Next(price int) int {
    spanner := 1    
    for i := this.count - 1; i >= 0; {
        if price < this.prices[i].price  {
            break
        }                
        spanner += this.prices[i].spanner
        i -= this.prices[i].spanner
    }
    this.prices = append(this.prices,&Spanner{
            price: price,
            spanner: spanner,
        })
    this.count++
    return spanner
}


/**
 * Your StockSpanner object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Next(price);
 */
```