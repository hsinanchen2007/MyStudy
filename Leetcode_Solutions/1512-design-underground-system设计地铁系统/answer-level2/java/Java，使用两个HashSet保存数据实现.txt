Java，使用两个HashSet保存数据实现，检出和查找的复杂度都是O(n)。
```
import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

public class UndergroundSystem {
    public class Info {
        public int id;
        public String inStationName;
        public int inTime;
        public int outTime;
        public String outStationName;
        public Info(int id, String name, int in) {
            this.id = id;
            this.inStationName = name;
            this.inTime = in;
        }
    }

    Set<Info> inSet;
    Set<Info> outSet;

    public UndergroundSystem() {
        inSet = new HashSet<>();
        outSet = new HashSet<>();
    }

    public void checkIn(int id, String stationName, int t) {
        inSet.add(new Info(id, stationName, t));
    }

    public void checkOut(int id, String stationName, int t) {
        Iterator<Info> it = inSet.iterator();
        while (it.hasNext()) {
            Info info = it.next();
            if (info.id == id) {
                info.outStationName = stationName;
                info.outTime = t;
                outSet.add(info);
                inSet.remove(info);
                break;
            }
        }
    }

    public double getAverageTime(String startStation, String endStation) {
        Iterator<Info> it = outSet.iterator();
        double sum = 0.0;
        int num = 0;
        while (it.hasNext()) {
            Info info = it.next();
            if (info.inStationName.equals(startStation) && info.outStationName.equals(endStation)) {
                sum += info.outTime - info.inTime;
                num ++;
            }
        }
        return sum / num;
    }
}
```
