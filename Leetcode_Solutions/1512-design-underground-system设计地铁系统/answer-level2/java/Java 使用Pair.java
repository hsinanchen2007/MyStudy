又学到一招，以为C++才有Pair。没想到Java也有Pair结构。

check: 记录相应id的人，进入的地铁站和时间。
time: 记录相同进出地铁站下，对应的总耗时和总人数。

```
class UndergroundSystem {
    // id -> <checkin_stationName, checkin_time>
    private Map<Integer, Pair<String, Integer>> check;
    // startStation+endStation -> <total_time,total_nums>
    private Map<String, Pair<Integer, Integer>> time;


    public UndergroundSystem() {
        check = new HashMap<>();
        time = new HashMap<>();
    }

    public void checkIn(int id, String stationName, int t) {
        check.put(id, new Pair<>(stationName, t));
    }

    public void checkOut(int id, String stationName, int t) {
        int checkin_time = check.get(id).getValue();
        String startStation = check.get(id).getKey();
        String k = startStation + stationName;

        Pair<Integer, Integer> pair = time.getOrDefault(k, new Pair<>(0, 0));
        time.put(k, new Pair<>(t - checkin_time + pair.getKey(), pair.getValue() + 1));
        check.remove(id);
    }

    public double getAverageTime(String startStation, String endStation) {
        Pair<Integer, Integer> pair = time.get(startStation + endStation);
        return (double)pair.getKey() / pair.getValue();
    }
}
```
