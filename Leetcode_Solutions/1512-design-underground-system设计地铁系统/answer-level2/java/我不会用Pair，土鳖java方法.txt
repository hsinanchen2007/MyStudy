```
class UndergroundSystem {
    HashMap<Integer,String> check;
    HashMap<String,int[]> average;

    public UndergroundSystem() {
        check = new HashMap<>();
        average = new HashMap<>();
    }
    
    public void checkIn(int id, String stationName, int t) {
        check.put(id,stationName+"-"+t);
    }
    
    public void checkOut(int id, String stationName, int t) {
        String[] ss = check.get(id).split("-");
        int time = t - Integer.parseInt(ss[1]);
        String line = ss[0] + '-' + stationName;
        if(average.containsKey(line)) {
            int[] old = average.get(line);
            average.put(line,new int[]{old[0]+1,old[1]+time});
        }else {
            average.put(line,new int[]{1,time});
        }
    }
    
    public double getAverageTime(String startStation, String endStation) {
        int[] old = average.get(startStation+'-'+endStation);
        return (double)old[1]/old[0];
    }
}

```
