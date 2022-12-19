### 解题思路
此处撰写解题思路

### 代码

```java
class UndergroundSystem {

    Map<Integer, String> idAndStation = new HashMap<Integer, String>();
	Map<Integer, Integer> idAndT= new HashMap<Integer,Integer>();
	Map<String,Long> sum = new HashMap<String,Long>();
	Map<String, Integer> num= new HashMap<String, Integer>();
	
	 public UndergroundSystem() {

	 }
	    
	 public void checkIn(int id, String stationName, int t) {
		this.idAndStation.put(id,stationName);
		this.idAndT.put(id,t);
	 }
	    
	  public void checkOut(int id, String stationName, int t) {
		 String code=idAndStation.get(id)+"*"+stationName;
		 int time =t-idAndT.get(id);
		 
		 if(!num.containsKey(code)) {
			 num.put(code, 0);
		 }
		 num.put(code, num.get(code)+1);
		 
		 if(!sum.containsKey(code)) {
			 sum.put(code, 0L);
		 }
		 sum.put(code, sum.get(code)+time);
	  }
	    
	  public double getAverageTime(String startStation, String endStation) {
		String code=startStation+"*"+endStation;
		Integer n = num.get(code);
		Long s = sum.get(code);
		 return 1.0*s/n; 
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