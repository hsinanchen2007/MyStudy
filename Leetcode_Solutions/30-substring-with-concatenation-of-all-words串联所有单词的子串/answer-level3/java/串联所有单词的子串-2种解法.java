欢迎大家关注我的LeetCode代码仓：[https://github.com/617076674/LeetCode]()
几乎所有题目都会提供多种解法，真诚求star！

# 解法一：单指针+哈希表

如果想到了哈希表的思想，该思路是最自然能想到的一个思路。该思路的步骤如下：

（1）新建一个哈希表map，其键为words数组中出现的单词，其值为该单词在words数组中出现的次数。

（2）对于字符串s中的每一个字符，我们都需要新建一个和map一模一样的哈希表tmpMap，该哈希表用以判断该字符是否是恰好串联words中所有单词的子串的起始位置。

（3）如果tmpMap中有该单词，那么将该单词在tmpMap中对应的次数减1。这也是我们为什么要新建一个和map一模一样的哈希表tempMap的原因，因为我们每次都会改变tmpMap的值。而如果我们改变了map的值，那么下一轮字符的参照表就不见了。如果没有该单词，直接判断字符串s中该位置的字符不是我们所要寻找的字符。

几个注意点：

（1）如果words中没有任何元素，我们返回的是一个空集合。

（2）我们不需要遍历字符串s中的每一个字符，我们只需要遍历字符串s中索引在[0, m - n * len]之间的字符即可，其中m为字符串s的长度，n为words数组的元素个数，len为words数组中的单词的长度。因为再往后遍历的话，所得到的字符串的长度都小于n * len了，显然是不满足条件的。

时间复杂度是O(m * n * len)。
空间复杂度是O(n)。

执行用时：150ms，击败66.03%。消耗内存：39.3MB，击败96.31%。

```java
public class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> result = new ArrayList<>();
        int n;
        if (null == words || (n = words.length) == 0) {
            return result;
        }
        int len = words[0].length();
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            if (map.containsKey(words[i])) {
                map.put(words[i], map.get(words[i]) + 1);
            } else {
                map.put(words[i], 1);
            }
        }
        for (int i = 0; i < s.length() - n * len + 1; i++) {
            Map<String, Integer> tmpMap = new HashMap<>(map);
            int j = 0;
            for (; j < len * n; j += len) {
                String subString = s.substring(i + j, i + j + len);
                if (!tmpMap.containsKey(subString)) {
                    break;
                } else {
                    tmpMap.put(subString, tmpMap.get(subString) - 1);
                    if (tmpMap.get(subString) == 0) {
                        tmpMap.remove(subString);
                    }
                }
            }
            if (j == len * n) {
                result.add(i);
            }
        }
        return result;
    }
}
```

# 解法二：滑动窗口+哈希表

这道题的题目中其实传递了一个很重要的信息：一些长度相同的words。长度相同意味着什么呢？

我们可以联系一下LeetCode003——无重复字符的最长子串中的滑动窗口法，惊奇地发现这题完全可以用滑动窗口法来解决！

对于每一个单词，既然它们的长度都相同，我们完全可以把它们看作是一个点来处理。但是我们也要注意不同之处，这里的滑动窗口的左右边界每一次行进的距离都是len，其中len为words数组中的单词的长度。因此我们需要使用len个滑动窗口，它们的起始位置分别是0、1、2、……、len - 1。

在处理每一个滑动窗口的时候我们都需要新建一个空的哈希表window，该哈希表用来记录我们的滑动窗口中包含的单词及其次数。

我们的滑动窗口的left指针指向的是滑动窗口中包含的第一个单词的第一个字符的位置，而right指针指向的是滑动窗口中包含的最后一个单词的最后一个字符的后一个位置，也就是说[left, right - 1]中包含的是我们的滑动窗口中的字符。初始化left和right指针均等于滑动窗口的起始位置i。

我们滑动窗口的滑动过程如下：

（1）判断right指针的右边的即将进入滑动窗口的单词tmpRight是否包含在map中，此处的map即解法一中建立的map。如果tmpRight没有包含在map中，很简单，我们更新right的值为right + len，left的值和right相等，清空哈希表window，并continue跳过本次循环即可。

（2）如果tmpRight包含在map中，将tmpRight加入到window。如果window中包含的tmpRight的数量大于map中包含的tmpRight的数量，我们需要移动我们的left指针直至window中包含的tmpRight的数量小于等于map中包含的tmpRight的数量，每次移动的距离也是len。

（3）如果right - left == n * len，其中n为words数组的元素个数，len为words数组中的单词的长度，说明我们找到了满足条件的一个滑动窗口，其左边界指针left就是恰好可以串联words中所有单词的子串的起始位置。

时间复杂度是O(m * len)，其中m为字符串s的长度，len为words数组中的单词长度。
空间复杂度是O(n)。

执行用时：10ms，击败99.81%。消耗内存：38.7MB，击败97.44%。

```java
public class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> result = new ArrayList<>();
        int n;
        if (null == words || (n =words.length) == 0) {
            return result;
        }
        int m = s.length(), len = words[0].length();
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < n; i++) {
            if (map.containsKey(words[i])) {
                map.put(words[i], map.get(words[i]) + 1);
            } else {
                map.put(words[i], 1);
            }
        }
        for (int i = 0; i < len; i++) {
            Map<String, Integer> window = new HashMap<>();
            int left = i, right = i;
            while (right < m - len + 1 && left < m - len * n + 1) {
                String tmpRight = s.substring(right, right + len);
                if (!map.containsKey(tmpRight)) {
                    right += len;
                    left = right;
                    window.clear();
                    continue;
                }
                if (!window.containsKey(tmpRight)) {
                    window.put(tmpRight, 1);
                } else {
                    window.put(tmpRight, window.get(tmpRight) + 1);
                }
                right += len;
                while (window.get(tmpRight) > map.get(tmpRight)) {
                    String tmpLeft = s.substring(left, left + len);
                    window.put(tmpLeft, window.get(tmpLeft) - 1);
                    if (window.get(tmpLeft) == 0) {
                        window.remove(tmpLeft);
                    }
                    left += len;
                }
                if (right - left == n * len) {
                    result.add(left);
                }
            }
        }
        return result;
    }
}
```
