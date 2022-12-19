```
class MapSum {

    Map<String, Integer> map = new HashMap<>();
    int sum;

    /**
     * Initialize your data structure here.
     */
    public MapSum() {

    }

    public void insert(String key, int val) {
        map.put(key, val);
    }

    public int sum(String prefix) {
        sum = 0;
        for (String key : map.keySet()) {
            if (key.indexOf(prefix) == 0) {
                sum += map.get(key);
            }
        }
        return sum;
    }
}
```
