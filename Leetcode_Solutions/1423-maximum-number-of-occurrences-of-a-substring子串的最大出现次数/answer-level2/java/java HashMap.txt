**思路**
1. 首先，题目的$maxSize$是没有用的，因为$maxSize$能够达到题目的最优解，$minSize$一定也能达到，因此只要考虑$minSize$即可。为什么这么说呢，我们举个例子，假设$s = "aababcaab"，minSize = 2，maxSize = 3$，那么我们通过$maxSize$算出的解是$"aab"$,出现两次，那么$"aab"$的子串$"aa"$一定也出现至少有两次（可能会超过两次）。
2. 然后，就是比较关键的$minSize$的大小 $1 <= minSize <= maxSize <= min(26, s.length)$。我们可以发现，这个$minSize$最大就是26。所以也就可以使用下面暴力算法了。
3. 题目中还有一个条件是 $子串中不同字母的数目必须小于等于 maxLetters$ 。 然后我们用一个Map来统计满足这个条件的所有$minSize$大小的子串出现的次数，都统计完之后后面计算出现次数最多的就是答案。

```java
class Solution {
 private boolean isMatch(String str, int maxLetters) {
        Set<Character> set = new HashSet<>();
        for (char c : str.toCharArray()) {
            set.add(c);
            if (set.size() > maxLetters) {
                return false;
            }
        }

        return set.size() <= maxLetters;
    }

    public int maxFreq(String s, int maxLetters, int minSize, int maxSize) {
        int len = s.length();
        Map<String, Integer> countMap = new HashMap<>();
        for (int i = 0; i < len; i++) {
            if (i + minSize > len) {
                break;
            }

            String sub = s.substring(i, i + minSize);
            if (isMatch(sub, maxLetters)) {
                countMap.put(sub, countMap.getOrDefault(sub, 0) + 1);
            }
        }

        int ansMax = 0;
        for (String str: countMap.keySet()) {
            int count = countMap.get(str);
            if (count > ansMax) {
                ansMax = count;
            }
        }

        return ansMax;
    }
}
```

**复杂度**
时间复杂度：$O(26*n)$,若忽略$26$这个系数，则为$O(n)$。
空间复杂度：$O(n)$