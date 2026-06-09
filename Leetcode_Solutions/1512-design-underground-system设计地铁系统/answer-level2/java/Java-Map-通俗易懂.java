### 解题思路

根据站台名或获取站台的流动人员信息。
站台信息包括入站的人员和出站的人员。
平均时间直接遍历起点站的入站人员和终点站的出站人员即可。

时间复杂度：和当前查询路线的站台的人数有关。
空间复杂度：$O(n+m)$，$n$表示站台数，$m$表示人数。

### 代码

```java
class UndergroundSystem {
    // K是站名，V是站台出入信息
    private Map<String, Station> stationMap;

    public UndergroundSystem() {
        stationMap = new HashMap<>();
    }

    public void checkIn(int id, String stationName, int t) {
        // 获取站台信息
        Station station = stationMap.getOrDefault(stationName, new Station());
        // 保存进站人id及其时间
        station.in.put(id, t);
        // 保存站台信息
        stationMap.put(stationName, station);
    }

    public void checkOut(int id, String stationName, int t) {
        // 同checkIn
        Station station = stationMap.getOrDefault(stationName, new Station());
        // 出站
        station.out.put(id, t);
        stationMap.put(stationName, station);
    }

    public double getAverageTime(String startStation, String endStation) {
        Station start = stationMap.get(startStation);
        Station end = stationMap.get(endStation);
        // 起点站的进站人id及其时间
        Map<Integer, Integer> in = start.in;
        // 终点站的出站人id及其时间
        Map<Integer, Integer> out = end.out;
        float total = 0;
        int num = 0;
        // 遍历进站的人
        for (int id : in.keySet()) {
            if (out.containsKey(id)) {
                // 编号为id的人从endStation出站
                // 总时间和总人数增加
                total += out.get(id) - in.get(id);
                ++num;
            }
            // 未出站的人不能算平均时间
        }
        return total / num;
    }

    // 站台信息
    private class Station {
        private Map<Integer, Integer> in = new HashMap<>();
        private Map<Integer, Integer> out = new HashMap<>();
    }
}

```

![图片.png](https://pic.leetcode-cn.com/a734b1cee22419878fdb1fed1863caa5f1646ce2250b274491ae4d39c50fb75d-%E5%9B%BE%E7%89%87.png)

