思路：
1、只关注minSize即可，因为如果长度为maxSize的字串出现了N次那么长度为minSize的字串出现次数也会是N
而题目要求返回出现次数最大的任意子串。
2、确定了长度以后就可以维护一个固定大小的滑动窗口去统计满足条件（不同字母的数目小于等于maxLetters）的
子串的出现次数了，统计次数可以借助map来做。
3、最后取个次数的最大值即可。
```
    public int maxFreq(String s, int maxLetters, int minSize, int maxSize) {
        char[] chars = s.toCharArray();
        Map<String, Integer> map = new HashMap<>();
        // 固定窗口大小的滑动窗口，枚举每个左边界的起始位置，那么右边界位置等于 i + minSize - 1
        for (int i = 0; i <= chars.length - minSize; i++) {
            if (counter(chars, i, i + minSize - 1) <= maxLetters) {
                String key = String.valueOf(chars, i, minSize);
                map.put(key, map.getOrDefault(key, 0) + 1);
            }
        }
        int max = 0;
        for (Integer value : map.values()) {
            max = Math.max(max, value);
        }
        return max;
    }

    // 用来统计不同元素的个数
    private int counter(char[] chars, int start, int end) {
        Set<Character> set = new HashSet<>();
        for (int i = start; i <= end; i++) {
            set.add(chars[i]);
        }
        return set.size();
    }
```
