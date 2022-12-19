### 解题思路
![Snipaste_2020-03-29_13-16-37.png](https://pic.leetcode-cn.com/fdab03575c0b723b58c8ad3d8307b86bb8330dfa9356d77991a65c5b149ba5be-Snipaste_2020-03-29_13-16-37.png)

定义了四个Map，可以用 Pair减少Map个数
给定输入已经严格限定了时间，无需进行时间，站点的判断，可以在出站时计算站点间时间，并且直接与之前保存的平均时间进行进一步计算

### 代码

```java
class UndergroundSystem {
    
    private Map<Integer,String> id_in_s;//保存进站人 Id 站名
    private Map<Integer,Integer> id_in_t;//保存进站时间
    private Map<String,Double> s_avrage_time;//保存站点间平均时间
    private Map<String,Integer> s_avrage_count;//保存站点间已计算平均时间的次数 

    public UndergroundSystem() {
        this.id_in_s=new HashMap<>();
        this.id_in_t=new HashMap<>();
        this.s_avrage_time=new HashMap<>();
        this.s_avrage_count=new HashMap<>();
    }
    
    public void checkIn(int id, String stationName, int t) {
        id_in_s.put(id,stationName);
        id_in_t.put(id,t);
    }
    
    public void checkOut(int id, String stationName, int t) {
        int in_t=id_in_t.get(id);
        String s_in=id_in_s.get(id);
        
        String start2endName=s_in+"#"+stationName;
        
        if(s_avrage_time.containsKey(start2endName)){
            double preavrage=s_avrage_time.get(start2endName);
            int count=s_avrage_count.get(start2endName);
            s_avrage_time.put(start2endName,(preavrage*count+t-in_t)/(count+1));
            s_avrage_count.put(start2endName,count+1);
        }else{
            s_avrage_time.put(start2endName,Double.valueOf(t-in_t));
            s_avrage_count.put(start2endName,1);
        }
        
    }
    
    public double getAverageTime(String startStation, String endStation) {
            return this.s_avrage_time.get(startStation+"#"+endStation);
    }
}
```