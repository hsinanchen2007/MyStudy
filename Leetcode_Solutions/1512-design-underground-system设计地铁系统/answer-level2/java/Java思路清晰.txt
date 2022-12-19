基本思路就和去数据库查表一样，要知道两个车站间的平均时间，所以首先就会有一个车站的记录。
车站记录的内容：记录的是谁来了，谁走了。如何确定是谁呢，就是通过乘客的id决定
乘客的记录内容是：什么时候来的，什么时候走的
其实可以接着套娃..确定了关系就好写了
```
class UndergroundSystem {
	class Station{
		String name ;
		Map<Integer, Integer> mapin =new HashMap<Integer,Integer>();//s
		Map<Integer, Integer> mapout =new HashMap<Integer, Integer>();
		public Station() {
			
		}
		public void setname(String n) {
			name = n;
		}
	}
	Map<String, Station> stations  ;
    public UndergroundSystem() {
    	stations = new HashMap<>();
    }
    
    public void checkIn(int id, String stationName, int t) {
    	if(!stations.containsKey(stationName)) {
    		Station station = new Station();
    		station.name = stationName;
    		stations.put(stationName, station);
    	}
    	if(!stations.get(stationName).mapin.containsKey(id)) {
    		stations.get(stationName).mapin.put(id, t);
    	}
    	Integer list = stations.get(stationName).mapin.get(id);
    	stations.get(stationName).mapin.put(id,list);
    }
    
    public void checkOut(int id, String stationName, int t) {
    	if(!stations.containsKey(stationName)) {
    		Station station = new Station();
    		station.name = stationName;
    		stations.put(stationName, station);
    	}
    	if(!stations.get(stationName).mapout.containsKey(id)) {
    		stations.get(stationName).mapout.put(id, t);
    	}
    	Integer list = stations.get(stationName).mapout.get(id);
    	stations.get(stationName).mapout.put(id,list);
    }
    
    public double getAverageTime(String startStation, String endStation) {
    	Station start = stations.get(startStation);
    	Station end   = stations.get(endStation);
    	double sum = 0 ;
    	double count =0;
    	for(int id:start.mapin.keySet()) {
    		if(end.mapout.containsKey(id)) {
    			sum += end.mapout.get(id)-start.mapin.get(id);
    			count++;
    		}
    	}
    	return sum/count;
    }
}
```
