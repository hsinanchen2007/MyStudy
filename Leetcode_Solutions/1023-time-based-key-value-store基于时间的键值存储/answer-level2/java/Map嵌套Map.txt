### 解题思路
Map嵌套Map，思路很简单，效率还可以？可能做得人太少。

### 代码

```java
class TimeMap {

   Map<String, Map<Integer, String>> maps;

    public TimeMap() {
        maps = new HashMap<>(120000);
    }

    public void set(String key, String value, int timestamp) {
        if (maps.containsKey(key)) {
            maps.get(key).put(timestamp, value);
        } else {
            Map<Integer, String> map = new HashMap<>();
            map.put(timestamp, value);
            maps.put(key, map);
        }
    }

    public String get(String key, int timestamp) {
        if (!maps.containsKey(key)) {
            return "";
        }
        Map<Integer, String> map = maps.get(key);
        if (map.containsKey(timestamp)) {
            return map.get(timestamp);
        }

        int timeStampTmp = timestamp;
        //这里有点挫，看描述递增的，可以用二分法查找，提升效率
        while (timeStampTmp > 0) {
            timeStampTmp--;
            if (map.containsKey(timeStampTmp)) {
                return map.get(timeStampTmp);
            }
        }
        return "";
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap obj = new TimeMap();
 * obj.set(key,value,timestamp);
 * String param_2 = obj.get(key,timestamp);
 */
```