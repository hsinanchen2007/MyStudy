![奇怪的知识增加了.jpg](https://pic.leetcode-cn.com/7f559d03203d255210df68a525117b1da540ad2ef34db6f273d0f67a77a50931-%E5%A5%87%E6%80%AA%E7%9A%84%E7%9F%A5%E8%AF%86%E5%A2%9E%E5%8A%A0%E4%BA%86.jpg)


### 代码

```java
class UndergroundSystem {
    HashMap<Integer, String> stName = new HashMap<>();
    HashMap<Integer, Integer> stTime = new HashMap<>();
    HashMap<String, Long> totalTime = new HashMap<>();
    HashMap<String, Integer> totalPerson = new HashMap<>();

    public UndergroundSystem() {
        stName.clear();
        stTime.clear();
        totalPerson.clear();
        totalTime.clear();
    }

    public void checkIn(int id, String stationName, int t) {
        stName.put(id, stationName);
        stTime.put(id, t);
    }

    public void checkOut(int id, String stationName, int t) {
        String str = stName.get(id);//获取出发站的名字
        int num = stTime.get(id);//获取出发时的时间
        if (totalTime.containsKey(str + "@@" + stationName)) {
            totalTime.put(str + "@@" + stationName, totalTime.get(str + "@@" + stationName) + t - num);
            totalPerson.put(str + "@@" + stationName, totalPerson.get(str + "@@" + stationName) + 1);
        } else {
            totalTime.put(str + "@@" + stationName, (long) t - num);
            totalPerson.put(str + "@@" + stationName, 1);
        }
    }

    public double getAverageTime(String startStation, String endStation) {
        return (double) totalTime.get(startStation + "@@" + endStation) / totalPerson.get(startStation + "@@" + endStation);
    }
}

```