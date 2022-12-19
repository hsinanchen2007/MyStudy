感觉还可以优化，我的能力只能这样了

```
var arr = new Array(num_people).fill(0)
    let num = 0
    while (candies > num) {
        arr[(num % num_people)] += ++num
        candies -= num
    }
    arr[(num % num_people)] += candies
    return arr
```
