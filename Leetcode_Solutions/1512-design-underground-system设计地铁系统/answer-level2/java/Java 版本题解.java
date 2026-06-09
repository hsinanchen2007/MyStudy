> 51 / 51 个通过测试用例
> 状态：通过
> 执行用时：99 ms
> 内存消耗：54.6 MB

```
import java.util.*;

class UndergroundSystem {

    private Map<String, List<Integer>> trR;
    private Map<Integer, String> inSR;
    private Map<Integer, Integer> inTR;
    
    public UndergroundSystem() {
        // key: 站a--站b, value: 时间
        trR = new HashMap<String, List<Integer>>();
        // id 进站名称
        inSR = new HashMap<Integer, String>();
        // id 进站时刻
        inTR = new HashMap<Integer, Integer>();
    }
    
    public void checkIn(int id, String stationName, int t) {
        inSR.put(id, stationName);
        inTR.put(id, t);
    }
    
    public void checkOut(int id, String stationName, int t) {
        String inS = inSR.get(id);
        Integer inT = inTR.get(id);
        String con = concat(inS, stationName);
        if(!trR.containsKey(con)) {
            trR.put(con, new ArrayList<Integer>());
        }
        trR.get(con).add(t - inT);
    }
    
    public double getAverageTime(String startStation, String endStation) {
        String cona = concat(startStation, endStation);
        // 总觉得要加一个反向的统计时间，String conb = concat(endStation, startStation);，但测试结果是不需要
        List<Integer> a = trR.get(cona);
        a = a == null? new ArrayList<Integer>(): a;
        
        double sum = 0;
        for(int i: a) {
            sum += i;
        }
        return sum / a.size();
    }
    
    private String concat(String a, String b) {
        return a + "--" + b;
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
