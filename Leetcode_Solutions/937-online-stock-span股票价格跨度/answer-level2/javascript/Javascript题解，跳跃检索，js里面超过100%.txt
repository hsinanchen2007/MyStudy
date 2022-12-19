![result.png](https://pic.leetcode-cn.com/9ce5c46036e65faefb0883745bf8b6e41a41a4dd0ccd1064042600df890c7664-result.png)


```
class StockSpanner {
    constructor() {
        this.data = [];
    }

    getCount(current) {
        if (this.data.length - 1 >= 0) {
            let max = 1;
            let index = this.data.length - 1;
            while (true) {
                if (index >= 0 && current >= this.data[index].price) {
                    max += this.data[index].count;
                    index -= this.data[index].count;
                } else {
                    break;
                }
            }
            return max;
        }
        return 1;
    }

    next(price) {
        const newPrice = {
            price,
            count: this.getCount(price)
        };
        this.data.push(newPrice);
        return newPrice.count;
    }
}
```
