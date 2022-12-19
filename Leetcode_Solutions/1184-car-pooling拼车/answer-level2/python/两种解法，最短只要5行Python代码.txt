# 1. 模拟法

[2, 1, 5]表示位置1处上车2人, 位置5处下车2人;

由此可见, 我们只要按实际情况去模拟,计算每次有人上车时是否会超载即可.

将[2, 1, 5]转换为[1, 2], [5, -2]。其中负数表示有人下车。

按位置由近到远排序, 位置相同的时候遵循**先下后上**的原则，即负数排在整数前。

```py
def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
    moves = []
    for trip in trips:
        moves.append((trip[1], trip[0]))
        moves.append((trip[2], -trip[0]))
    moves.sort()
    
    total = 0
    for move in moves:
        total += move[1]
        if total > capacity:
            return False
    return True
```

# 2. 计算每个位置的人数

计算每个位置的总人数, 没有大于capacity的位置说明不会超载. 

[2, 1, 5]表示位置1，2，3，4，处都会增加2个人. 

问题就变成了给定一个区间, 为区间内的每个数都增加一个相同的数; 求最后每个位置的总人数.

这和[Corporate Flight Bookings](https://leetcode.com/problems/corporate-flight-bookings/)这题一模一样.

可以参考这位大神给出的[解法](https://leetcode.com/problems/corporate-flight-bookings/discuss/328856/JavaC%2B%2BPython-Straight-Forward-Solution)

```python []
from itertools import accumulate, dropwhile

class Solution:
    def carPooling(self, trips: List[List[int]], capacity: int) -> bool:
        numberOfPeople = [0] * 1001
        for number, start, end in trips:
            numberOfPeople[start] += number
            numberOfPeople[end] -= number
        return not list(dropwhile(lambda x: x <= capacity, accumulate(numberOfPeople)))
```
```java []
class Solution {
    public boolean carPooling(int[][] trips, int capacity) {
        int[] numberOfPeople = new int[1001];
        for (int[] trip: trips) {
            numberOfPeople[trip[1]] += trip[0];
            numberOfPeople[trip[2]] -= trip[0];
        }

        for (int i = 1; i < 1001; i++) {
            numberOfPeople[i] += numberOfPeople[i - 1];
            if (numberOfPeople[i] > capacity) {
                return false;
            }
        }
        return true;
    }
}
```

