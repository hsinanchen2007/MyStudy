插入和删除O1很好实现，但是getRandom要O1可能有点问题，这里我直接取出map的键集合，然后直接对其求random取出key来实现。

```java
class RandomizedSet {

    private HashMap<Integer, Object> map;

    public RandomizedSet() {
        this.map = new HashMap<>(8);
    }

    public boolean insert(int val) {
        if (map.keySet().contains(val)) {
            return false;
        } else {
            map.put(val, new Object());
            return true;
        }
    }

    public boolean remove(int val) {
        if (map.keySet().contains(val)) {
            map.remove(val);
            return true;
        } else {
            return false;
        }
    }

    public int getRandom() {
        Integer[] keys = map.keySet().toArray(new Integer[]{});
        return keys[new Random().nextInt(keys.length)];
    }
}
```
