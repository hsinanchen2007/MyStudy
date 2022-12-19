### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for (int i = 0; i < deck.length; i++) {
            map.put(deck[i], map.getOrDefault(deck[i], 0) + 1);
        }
        int res = map.get(deck[0]);
        for (int k : map.keySet()) {
            res = gcd(res, map.get(k));
        }
        return res > 1;
    }

    int gcd(int x, int y) {
        if (y == 0) return x;
        return gcd(y, x % y);
    }
}
```