### 法一
思想是求出每个元素的个数，然后判断这些元素的最大公约数。这里采用HashMap计数。

### 代码

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        Map<Integer, Integer> map = new HashMap<>();
        int temp = 0;
        for (int i = 0; i < deck.length; i++) {
            if (null != map.get(deck[i])) {
                temp = map.get(deck[i]);
                map.put(deck[i], ++temp);
            } else {
                map.put(deck[i], 1);
            }
        }
        Iterator<Integer> iterator = map.values().iterator();
        int gcd = 1;
        if (iterator.hasNext()) {
            gcd = iterator.next();
        }
        while (iterator.hasNext()) {
            gcd = gcd(gcd, iterator.next());
            if (1 == gcd) {
                return false;
            }
        }

        return gcd >= 2;
    }

    private int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}
```
### 法二
思路同一，但是根据题目条件采用数组计数。

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        int N = 10000;
        int[] table = new int[N];
        int max = 0;
        for (int i = 0; i < deck.length; i++) {
            max = deck[i] > max ? deck[i] : max;
            table[deck[i]]++;
        }
        int gcd = table[deck[0]];
        for (int i = 0; i <= max; i++) {
            if (0 == table[i]) continue;
            gcd = gcd(gcd, table[i]);
            if (1 == gcd) {
                return false;
            }
        }
        return gcd >= 2;
    }

    private int gcd(int a, int b) {
        return 0 == b ? a : gcd(b, a % b);
    }
}
```

### 法三（法二的优化）
思路也同法二，但是在计算最大公约数的时候采用合并的思想，这样时间为O(Log(N))

```java
class Solution {
    public boolean hasGroupsSizeX(int[] deck) {
        int N = 10000;
        int[] table = new int[N];
        int max = 0;
        for (int i = 0; i < deck.length; i++) {
            max = deck[i] > max ? deck[i] : max;
            table[deck[i]]++;
        }
        int gcd = maxGCD(table, 0, max);
        return gcd >= 2;
    }

    private int maxGCD(int[] table, int left, int right) {
        if (left == right) {
            return table[left];
        }
        if (left + 1 == right) {
            return gcd(table[left], table[right]);
        }

        int middle = (left + right) / 2;
        int gcdLeft = maxGCD(table, left, middle);
        int gcdRight = maxGCD(table, middle, right);

        return gcd(gcdLeft, gcdRight);
    }

    private int gcd(int a, int b) {
        return 0 == b ? a : gcd(b, a % b);
    }
}
```
