### 解法

```java
public class UndergroundSystem {
    private Map<String, Integer> time;
    private Map<String, Integer> count;
    private Map<Integer, Integer> idToTime;
    private Map<Integer, String> idToStation;
    public UndergroundSystem() {
        time = new HashMap<>();
        count = new HashMap<>();
        idToTime = new HashMap<>();
        idToStation = new HashMap<>();
    }

    public void checkIn(int id, String stationName, int t) {
        idToTime.put(id, t);
        idToStation.put(id, stationName);
    }

    public void checkOut(int id, String stationName, int t) {
        int startTime = idToTime.get(id);
        String startStation = idToStation.get(id);
        String stationInfo = startStation + stationName;
        time.put(stationInfo, time.getOrDefault(stationInfo, 0) + t - startTime);
        count.put(stationInfo, count.getOrDefault(stationInfo, 0) + 1);
    }

    public double getAverageTime(String startStation, String endStation) {
        String stationInfo = startStation + endStation;
        return time.get(stationInfo) * 1.0 / count.get(stationInfo);
    }
}
```

思路分析：

* 首先说一下我在写这个题的时候，被罚时的一次，我考虑漏了同一个人可能会进出地铁站多次，我考虑一个id只会对应一个路线。
* 题目说了，所有`api`的调用都符合逻辑。所以某一个`id`（后文使用某一个人这样的称呼）调用了`checkIn`后才会调用`checkOut`，某一个人调用了`checkIn`之后，没有调用`checkOut`前不能再调用`checkIn`。所以使用一个`Map<Integer, Integer> idToTime`来存放某个人（id）`checkIn`的时间，以`id`为键，进入时间为值。这样做不会出现信息覆盖，因为：
    * 调用`checkOut`之前，不会有这个人调用`checkIn`，不会信息覆盖。
    * 调用`checkOut`之后，这个人调用`checkIn`，之前的信息已经被处理过了，覆盖也无所谓。
* 类似的想法，我们使用`Map<Integer, String> idToStation`来放某个人（id）`checkIn`的初始站台名称，以`id`为键，进入的站台名为值，也不会出现信息覆盖。
* 记录进站的时间地点信息，是为了在出站的时候，存放该路线的信息。包括该人次该路线停留的时间，及更新该路线一共有多少人次走过（注意是人次，不是该人）。
* 存放这两个信息是为了`getAverageTime`服务，使用`Map<String, Integer> time`记录该线路上花费的总时间，使用`Map<String, Integer> count`记录该线路总的出行人次。这两个量直接求平均，注意返回值是`double`类型喔😁。
    * 解释一下键。键是用初始站的名字与结束站的名字拼接而成的，没有同名车站，所以这样的拼接方式与线路一一对应（初始站于结束站唯一确定线路）
    * 由于所需要的数据都是存好的，只需要从`hashmap`中`get`出来即可。时间复杂度为$O(1)$的。
* 3个`api`的时间复杂度都是$O(1)$的。

代码解释：

* `checkIn`只将初始信息进行存储。
* `checkOut`先通过`id`得到初始信息，然后`String stationInfo = startStation + stationName`唯一确定路线，再将完成了的这个出行的时间累加入该线路的总时间上`time.put(stationInfo, time.getOrDefault(stationInfo, 0) + t - startTime);`，将该线路的出行人次+1`count.put(stationInfo, count.getOrDefault(stationInfo, 0) + 1);`。

更多LeetCode题解请看我的[github](https://github.com/ustcyyw/yyw_algorithm)，地址https://github.com/ustcyyw/yyw_algorithm。还有别的小项目也很好玩~卑微求个小星星💖