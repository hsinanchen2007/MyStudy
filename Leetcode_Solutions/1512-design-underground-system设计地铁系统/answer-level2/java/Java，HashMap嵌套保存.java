![QQ截图20200329123056.png](https://pic.leetcode-cn.com/77dcc069610cbb2439faab24086a43d0b138d8bf45835625abfd5e5e74b77467-QQ%E6%88%AA%E5%9B%BE20200329123056.png)


```
class UndergroundSystem {

    public class TotalAndTimes{
        double total;
        double times;
    }
    HashMap<Integer,HashMap<String,Integer>> clientMap = new HashMap<>();
    HashMap<String,HashMap<String,TotalAndTimes>> resultMap = new HashMap<>();
    public UndergroundSystem() {

    }

    public void checkIn(int id, String stationName, int t) {
        HashMap<String,Integer> client = clientMap.getOrDefault(id,new HashMap<>());
        client.put(stationName,t);
        clientMap.put(id,client);
    }

    public void checkOut(int id, String stationName, int t) {
        HashMap<String,Integer> checkInTimes = clientMap.get(id);
        checkInTimes.forEach((key,value)->{
            HashMap<String,TotalAndTimes> result = resultMap.getOrDefault(key,new HashMap<>());
            TotalAndTimes totalAndTimes = result.getOrDefault(stationName,new TotalAndTimes());
            totalAndTimes.times+=(t-value);
            totalAndTimes.total++;
            result.put(stationName,totalAndTimes);
            resultMap.put(key,result);
        });
    }

    public double getAverageTime(String startStation, String endStation) {
        double times = resultMap.get(startStation).get(endStation).times;
        double total = resultMap.get(startStation).get(endStation).total;
        return times/total;
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
