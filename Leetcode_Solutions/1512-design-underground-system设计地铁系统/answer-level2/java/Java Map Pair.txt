```java
class UndergroundSystem {
    Map<Integer, Pair<String, Integer>> checkInMap = new HashMap<>();
    Map<String, Pair<Integer, Integer>> checkOutMap = new HashMap<>();
    UndergroundSystem() {

    }
    
    void checkIn(int id, String stationName, int t) {
        checkInMap.put(id, new Pair<>(stationName, t));
    }
    
    void checkOut(int id, String stationName, int t) {
        Pair<String, Integer> checkIn = checkInMap.get(id);
        String route = checkIn.getKey() + "#" + stationName;
        int time = t - checkIn.getValue();
        Pair<Integer, Integer> checkout = checkOutMap.getOrDefault(route, new Pair<>(0, 0));
        checkOutMap.put(route, new Pair<>(checkout.getKey() + time, checkout.getValue() + 1));
    }
    
    double getAverageTime(String startStation, String endStation) {
        Pair<Integer, Integer> checkout = checkOutMap.getOrDefault(startStation + "#" + endStation, new Pair<>(0, 0));
        return (double)checkout.getKey() / checkout.getValue();
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