```java
class TimeMap {

    private Map<String, List<Value>> map;
    /** Initialize your data structure here. */
    public TimeMap() {
        map = new HashMap<>();
    }

    public void set(String key, String value, int timestamp) {
        List<Value> list = map.getOrDefault(key, new ArrayList<>());
        list.add(new Value(value, timestamp));
        map.put(key, list);
    }

    public String get(String key, int timestamp) {
        List<Value> list = map.get(key);
        String val = "";
        int i = Collections.binarySearch(list, new Value("", timestamp));
        if (i < 0) {
            i = (-i) - 2;
        }
        if (i >= 0) {
            val = list.get(i).value;
        }
        return val;
    }


    private static class Value implements Comparable<Value>{
        String value;
        int timestamp;

        Value(String value, int timestamp) {
            this.value = value;
            this.timestamp = timestamp;
        }

        @Override
        public int compareTo(Value o) {
            return timestamp - o.timestamp;
        }

    }

}
```
