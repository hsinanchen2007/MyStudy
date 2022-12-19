### 解题思路
在出站的时候，将入站和出站的stationName加起来变成一个Map的key，再把<时间,次数>组合成一个pair，这样计算平均时间就好算了

### 代码

```java
class UndergroundSystem {

    Map<Integer, Pair<String, Integer>> map = new HashMap<>();
    Map<String, Pair<Integer, Float>> time = new HashMap<>();

    public UndergroundSystem() {

    }

    public void checkIn(int id, String stationName, int t) {
        map.put(id, new Pair<>(stationName, t));
    }

    public void checkOut(int id, String stationName, int t) {
        Pair<String, Integer> nameAndTime = map.get(id);

        String k = nameAndTime.getKey() + stationName;

        Pair<Integer, Float> pair = time.getOrDefault(k, new Pair<>(0, 0.0f));

        Integer kk = t - nameAndTime.getValue() + pair.getKey();
        Float vv = pair.getValue() + 1.0f;

        time.put(k, new Pair<>(kk, vv));

        map.remove(id);
    }

    public double getAverageTime(String startStation, String endStation) {
        String k = startStation + endStation;
        Pair<Integer, Float> pair = time.get(k);
        return pair.getKey()/pair.getValue();
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