## 1. 标准哈希表
```java
class Solution {
    public int numRabbits(int[] ans) {
        Map<Integer, Integer> map = new HashMap<>(ans.length);
        int num = 0;
        for (int n : ans) {
            if (!map.containsKey(n) || map.get(n) == n + 1) {
                num += (n + 1);
                map.put(n, 1);
            } else {
                map.put(n, map.getOrDefault(n, 0) + 1);
            }
        }
        return num;
    }
}
```

## 2. 使用数组提高效率
```java
class Solution {
    public int numRabbits(int[] ans) {
        int[] map = new int[1000];
        int num = 0;
        for (int n : ans) {
            if (map[n] == 0 || map[n] == n + 1) {
                num += (n + 1);
                map[n] = 1;
            } else {
                map[n]++;
            } 
        }
        return num;
    }
}
```
