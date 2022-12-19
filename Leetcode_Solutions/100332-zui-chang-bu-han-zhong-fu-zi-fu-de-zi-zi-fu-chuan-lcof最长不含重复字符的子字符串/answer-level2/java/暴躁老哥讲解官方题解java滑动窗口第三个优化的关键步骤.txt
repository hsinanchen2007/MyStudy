Leetcode官方题解3：优化的滑动窗口start = Math.max(map.get(s.charAt(end)) + 1, start);秀你🐴🍺呢？

我来讲解下很多人为啥疑问的这一步start = Math.max(map.get(s.charAt(end)) + 1, start);

如果是按照普通滑动窗口的算法，如果i到j内无重复，j +1的位置跟k重复了，通常会将i到k之间的元素从set中移除，这点无可厚非
但是方法三优化了这个反复remove的过程，举个具体例子：
abcdefghcbijklmnopqrst,求这个最长无重复子串
由于使用了一个hashmap来记录之前保存的每一个字母以及对应的位置
比如现在窗口的start为0，end为7,
往下走，end坐标增加到8时，发现之前有重复的了，于是就丢弃之前的窗口（坐标0到坐标2）于是现在start坐标为3
继续往下走，发现end坐标增加到9，对应位置的字母是b，然后从map里找之前出现过的位置为2，不过这时候发现start已经为3了，所以不需要再计算坐标3之前的了
所以start还是在3的位置，但是我要举个反例：
比如假如给定字符串为：
abcdefghcfijklmnopqrst，
同样的情形，当end坐标增加到9时，在之前的过程，由于c的重复，start坐标已经变成了3,这时候发现坐标9的位置是f，坐标5的位置也是，所以start应该增加到6
比如序列中出现了好几次f，这样通过一次次的更新map，字母f出现所对应的坐标也在不断增加，所以根本不需要关心，在出现重复字母时，把前一次出现的元素从map
里移除,以达到提高算法效率的目的
贴上我的代码：

```java
    public int lengthOfLongestSubstring(String s) {
        int n = s.length(), ans = 0;
        Map<Character, Integer> map = new HashMap<>();//key出现的字符，value对应的最新的位置
        // try to extend the range [i, j]
        for (int end = 0, start = 0; end < n; end++) {
            if (map.containsKey(s.charAt(end))) {
                start = Math.max(map.get(s.charAt(end)) + 1, start);//由于重复的坐标不知道在start的前方还是后方，所以要取个最大值
            }
            ans = Math.max(ans, end - start + 1);
            map.put(s.charAt(end), end);
        }
        return ans;
    }
```