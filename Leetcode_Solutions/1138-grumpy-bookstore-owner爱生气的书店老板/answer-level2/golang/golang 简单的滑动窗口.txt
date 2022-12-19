这题用滑动窗口可以很容易，很快的想到

1. 先计算所有老板没有生气时的客人数量计算
```
for i := 0; i < len(customers); i++ {
        if grumpy[i] == 0 {
            sum += customers[i]
        }
}
```
2. 计算从0 - (x-1) 老板不生气的值
```
t  := 0
for i := 0; i < X; i++ {
        if grumpy[i] == 1 {
            t += customers[i]
        }
}
max := t
```
3.开始滑动窗口。当前是0-(x-1), 那么下一刻是（1-x) 。如果i时老板生气了，那么t +customers[i]。同时，如果 i- x时生气了，需要减掉。计算每次滑动的最大值
```
 for i := X; i < len(customers); i++ {
        if grumpy[i] == 1 {
            t += customers[i]
        }
        if grumpy[i - X] == 1 {
            t -= customers[i - X]
        }
        max = Max(t, max)
}
```
完整代码：
```
func maxSatisfied(customers []int, grumpy []int, X int) int {
    sum := 0
    for i := 0; i < len(customers); i++ {
        if grumpy[i] == 0 {
            sum += customers[i]
        }
    }
    t := 0
    for i := 0; i < X; i++ {
        if grumpy[i] == 1 {
            t += customers[i]
        }
    }
    max := t
    for i := X; i < len(customers); i++ {
        if grumpy[i] == 1 {
            t += customers[i]
        }
        if grumpy[i - X] == 1 {
            t -= customers[i - X]
        }
        max = Max(t, max)
    }
    return sum + max
}

func Max(x, y int) int {
    if x > y {
        return x
    }
    return y
}
```