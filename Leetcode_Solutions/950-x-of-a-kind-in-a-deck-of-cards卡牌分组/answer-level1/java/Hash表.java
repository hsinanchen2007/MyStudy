### 解题思路
哈希表+最大公约数
不过用哈希表确实慢，不如改成int[] map = new int[10000]

### 代码

```java
class Solution {
    public static boolean hasGroupsSizeX(int[] deck) {
        //hash表记录数字出现个数
        int length = deck.length;
        Map<Integer, Integer> map = new HashMap<>();
        for(int i = 0; i < length; i++) {
            if (map.containsKey(deck[i])) {
                map.put(deck[i], map.get(deck[i])+1);
            } else {
                map.put(deck[i], 1);
            }
        }
        int gcd = map.get(deck[0]);
        for(Map.Entry<Integer, Integer> m : map.entrySet()) {
            int val = m.getValue();
            gcd = getGCD(gcd, val);
            if(gcd < 2) {
                return false;
            }
        }
        return true;
    }

    private static int getGCD(int a, int b) {
        return a%b == 0? b : getGCD(b, a%b);
    }
}
```