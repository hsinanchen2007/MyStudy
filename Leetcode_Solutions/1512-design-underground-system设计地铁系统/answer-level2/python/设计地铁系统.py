#### 方法一：哈希映射

我们需要两张哈希表。一张用来存编号为 `id` 的乘客的进站信息，键为 `id`，值需要保存两个信息：站点名字和进站时间。另一张用来存放以 `s` 为起点站，`e` 为终点站的已经出站的乘客的信息，键为 `(s, e)`，值也需要保存两个信息：花费的总时间和已经出站的总人数。

在 `checkIn` 的时候，我们对第一张表进行操作，保存进站信息。在 `checkOut` 的时候，我们先从第一张表中查询这个 `id` 的进站信息 `(startStation, startTime)`，然后修改第二张表，把总时间加上 `t - startTime`，总人数自增一。在 `getAverageTime` 的时候直接查询第二张表得到 `(sum, amount)`，计算平均值。

**代码**

```cpp [sol1-cpp]
class UndergroundSystem {
public:
    using Start = pair <string, int>;
    using StartEnd = pair <string, string>;
    using SumAndAmount = pair <int, int>;

    struct StartEndHash {
        int operator() (const StartEnd& x) const{
            return hash <string> () (x.first + x.second);
        }
    };

    unordered_map <int, Start> startInfo;
    unordered_map <StartEnd, SumAndAmount, StartEndHash> table;
    
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        startInfo[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto startTime = startInfo[id].second;
        table[{startInfo[id].first, stationName}].first += t - startTime;
        table[{startInfo[id].first, stationName}].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto sum = table[{startStation, endStation}].first;
        auto amount = table[{startStation, endStation}].second;
        return double(sum) / amount;
    }
};
```

```python [sol1-python]
class UndergroundSystem:
    def __init__(self):
        self.startInfo = dict()
        self.table = dict()

    def checkIn(self, id: int, stationName: str, t: int) -> None:
        self.startInfo[id] = (stationName, t)

    def checkOut(self, id: int, stationName: str, t: int) -> None:
        startTime = self.startInfo[id][1]
        index = (self.startInfo[id][0], stationName)
        rec = self.table.get(index, (0, 0))
        self.table[index] = (rec[0] + t - startTime, rec[1] + 1)


    def getAverageTime(self, startStation: str, endStation: str) -> float:
        index = (startStation, endStation)
        sum, amount = self.table[index]
        return sum / amount
```

**复杂度分析**

+ 时间复杂度：从代码可以看出，这里 `checkIn`、`checkOut` 和 `getAverageTime` 的渐进时间复杂度都是 $O(1)$。

+ 空间复杂度：这里我们用到了两张哈希表作为辅助空间。假设这里操作的总次数为 $n$，那么第一张表的键的总数为 $O(n)$，第二张表键的总数也为 $O(n)$，故渐进空间复杂度为 $O(n ^ 2)$。