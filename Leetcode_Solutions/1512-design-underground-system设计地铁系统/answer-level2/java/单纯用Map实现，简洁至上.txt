### 解题思路
station2Time：{起始-终点车站, 总时长}
station2Count：{起始-终点车站, 总乘车次数}
inTime：{id, 进站时间}
inStation：{id, 进站车站}
各个操作时间复杂度都是$O(1)$，空间复杂度则是$O(N)$，N代表路线数（id数肯定小于等于路线数所以是$O(N)$）。

### 代码

```java
class UndergroundSystem {
    private Map<String, Integer> station2Time;
    private Map<String, Integer> station2Count;
    private Map<Integer, Integer> inTime;
    private Map<Integer, String> inStation;

    public UndergroundSystem() {
        station2Time = new HashMap<>();
        station2Count = new HashMap<>();
        inTime = new HashMap<>();
        inStation = new HashMap<>();
    }
    
    public void checkIn(int id, String stationName, int t) {
        inTime.put(id, t);
        inStation.put(id, stationName);
    }
    
    public void checkOut(int id, String stationName, int t) {
        String in_station = inStation.get(id);
        int in_time = inTime.get(id);
        String in_out = in_station + "-" + stationName;
        if (station2Time.containsKey(in_out)) {
            station2Time.put(in_out, station2Time.get(in_out) + t - in_time);
            station2Count.put(in_out, station2Count.get(in_out) + 1);
        }
        else {
            station2Time.put(in_out, t - in_time);
            station2Count.put(in_out, 1);
        }
    }
    
    public double getAverageTime(String startStation, String endStation) {
        String in_out = startStation + "-" + endStation;
        return station2Time.get(in_out) * 1.0 / station2Count.get(in_out);
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