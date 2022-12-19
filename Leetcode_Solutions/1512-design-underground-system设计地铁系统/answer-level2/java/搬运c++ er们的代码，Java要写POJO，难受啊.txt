把两个车站的name 用 '-' 连接起来最好做。

```java
class UndergroundSystem {
    
    public UndergroundSystem() {

    }
    private Map<Integer, Station> map = new HashMap<>();
    private Map<String, Data> map1 = new HashMap<>();
    public void checkIn(int id, String stationName, int t) {
        Station station = new Station(stationName, t);
        map.put(id, station);
    }

    public void checkOut(int id, String stationName, int t) {
        String way = map.get(id).stationNmae + "-" + stationName;
        Data data = map1.getOrDefault(way, new Data());
        data.count++;
        data.gapeTime += (t - map.get(id).t);
        map1.put(way, data);
    }

    public double getAverageTime(String startStation, String endStation) {
        String way = startStation + "-" + endStation;
        return map1.get(way).gapeTime / (double)map1.get(way).getCount(); 
    }
    class Data {
        int count;
        int gapeTime;

        public Data() {
        }

        public Data(int count, int gapeTime) {
            this.count = count;
            this.gapeTime = gapeTime;
        }

        public int getCount() {
            return count;
        }

        public void setCount(int count) {
            this.count = count;
        }

        public int getGapeTime() {
            return gapeTime;
        }

        public void setGapeTime(int gapeTime) {
            this.gapeTime = gapeTime;
        }
    }
    class Station {
        String stationNmae;
        int t;

        public Station(String stationNmae, int t) {
            this.stationNmae = stationNmae;
            this.t = t;
        }

        public String getStationNmae() {
            return stationNmae;
        }

        public void setStationNmae(String stationNmae) {
            this.stationNmae = stationNmae;
        }

        public int getT() {
            return t;
        }

        public void setT(int t) {
            this.t = t;
        }
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