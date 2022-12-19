### 解题思路
使用单调递减栈维护日期和股票价格

### 代码

```golang []
type Price struct {
	price int
	date  int
}
type StockSpanner struct {
	date  int
	stack []Price
}

func Constructor() StockSpanner {
	return StockSpanner{
		date:  0,
		stack: make([]Price, 0),
	}
}

func (ss *StockSpanner) Next(price int) int {
	for len(ss.stack) > 0 && ss.stack[len(ss.stack)-1].price <= price {
		ss.stack = ss.stack[:len(ss.stack)-1]
	}
	ss.date++
	var res = ss.date
	if len(ss.stack) > 0 {
		res = ss.date - ss.stack[len(ss.stack)-1].date
	}
	ss.stack = append(ss.stack, Price{
		price: price,
		date:  ss.date,
	})

	return res
}
```
```java []
class StockSpanner {
    private static class Price {
        int date;
        int price;

        public Price(int date, int price) {
            this.date = date;
            this.price = price;
        }
    }

    private int date;
    private Stack<Price> prices;

    public StockSpanner() {
        prices = new Stack<>();
    }

    public int next(int price) {
        while (!prices.empty() && prices.peek().price <= price) {
            prices.pop();
        }
        date++;
        int res = date;
        if (!prices.empty()) {
            res = date - prices.peek().date;
        }
        prices.push(new Price(date, price));
        return res;
    }
}
```