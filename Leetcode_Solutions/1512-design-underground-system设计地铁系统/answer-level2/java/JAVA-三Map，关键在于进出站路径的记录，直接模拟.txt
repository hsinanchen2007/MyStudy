### 解题思路

本题的关键点在于求**两个站点**的平均时间消耗，那么自然，要进站是startStation，出站是endStation的才满足条件。所以，记录下人员进出站路径，就非常重要了。

于是，在出站的时候，就统计消耗的时间差，同时乘车记录+1，然后记录到startStation->endStation这条路径的统计中。

人员入站的时候，记录下当前人员的进站地点和进站时间，在人员出站的时候取出，出站时间-进站时间为时间消耗。

最终统计平均耗时的时候，只要把startStation->endStation路径中累计的**耗时/次数**即可。

时间复杂度O(1)，空间复杂度3个Map,为O(N)。

### 代码

```java
class UndergroundSystem {

    // 人员的进站地点
    private Map<Integer, String> manInStation = new HashMap<>();
    // 人员进站时间
    private Map<Integer, Integer> manInStationTime = new HashMap<>();
    // s->e的时间差和次数
    private Map<String, int[]> stationTime = new HashMap<>();

    public UndergroundSystem() {

    }

    // 进站
    public void checkIn(int id, String stationName, int t) {
        // 人员进站地点和时间
        manInStation.put(id, stationName);
        manInStationTime.put(id, t);
    }

    // 出站
    public void checkOut(int id, String stationName, int t) {
        // 获取进站地点和时间
        String inStation = manInStation.get(id);
        int st = manInStationTime.get(id);
        // 获取本次路程时间差和次数
        int[] time = stationTime.computeIfAbsent(getJourney(inStation,stationName), k -> new int[]{0, 0});
        time[0] += t - st;// 出入站时间消耗
        time[1]++;// 次数累计
    }

    public double getAverageTime(String startStation, String endStation) {
        int[] time = stationTime.get(getJourney(startStation,endStation));
        return 1D * time[0]/time[1];
    }

    // 获取路程
    private String getJourney(String startStation,String endStation){
        return startStation + "->" + endStation;
    }
}

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem obj = new UndergroundSystem();
 * obj.checkIn(id,stationName,t);
 * obj.checkOut(id,stationName,t);
 * double param_3 = obj.getAverageTime(startStation,endStation);
 */
```