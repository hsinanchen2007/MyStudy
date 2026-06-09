比较经典的滑动窗口题目, 只不过需要记录一个k值.
所以窗口左侧index应该要遍历整个窗口找到对应字符出现最晚的时间，并从这些时间里找到最早的一个，将这个位置更新到新的窗口即可。
具体请看函数：getFirstMap
其他的看代码注释就好了。

```
import java.util.HashMap;
import java.util.Map;

class Solution {
    public int lengthOfLongestSubstringKDistinct(String s, int k) {
        if (k <= 0) {
            return 0;
        }

        if ((s == null) || s.isEmpty()) {
            return 0;
        }

        Map<Character, Integer> indexMap = new HashMap<>();
        int preIndex = 0;
        int result = 0;
        for (int i = 0, size = s.length(); i < size; i++) {
            // 如果之前窗口没有满.
            // 1. 窗口里不同数的个数 < k
            // 2. 窗口个数 == k 但是窗口里面已经包含了这个数
            if (indexMap.size() < k || (indexMap.containsKey(s.charAt(i)))) {
                // 将这个字符最后出现的位置记录到窗口里
                indexMap.put(s.charAt(i), i);
                result = Math.max(result, i - preIndex + 1);
                continue;
            }

            // 获取前面字符出现的最后的哪一个
            // aaabc：遍历到c的时候,应该将要第3个a获取到
            // abbbbc：遍历到c的时候, 应该将第1个a获取到
            Map.Entry<Character, Integer> entry = getFirstMap(indexMap);

            // 更新preIndex. 用于窗口的最左侧
            preIndex = entry.getValue() + 1;

            // 移除这个字符, 并将新的字符加进去
            indexMap.remove(entry.getKey());
            indexMap.put(s.charAt(i), i);
        }
        return result;
    }

    private Map.Entry<Character, Integer> getFirstMap(Map<Character, Integer> map) {
        Map.Entry<Character, Integer> result = null;
        int index = Integer.MAX_VALUE;
        for (Map.Entry<Character, Integer> entry : map.entrySet()) {
            if (entry.getValue() < index) {
                result = entry;
                index = entry.getValue();
            }
        }
        return result;
    }
}
```
