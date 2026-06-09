### 解题思路
执行用时 :24 ms, 在所有 Java 提交中击败了46.89%的用户
内存消耗 :39.3 MB, 在所有 Java 提交中击败了100.00%的用户


方法2： 勉强通过，用一个容器记录最大字符的所有开始位置，然后比较从各个开始位置的最大字符串

### 代码
方法一 如果不是最大字符，但是前面有重复的情况，会有冗余操作
```java
class Solution {
    public String lastSubstring(String s) {
        if (s == null) {
            return "";
        }
        if (s.length() <= 1) {
            return s;
        }
        char maxC = ' ';
        int maxStart = 0;
        int pre = 0;
        for (int i = 0; i < s.length(); i++) {
            char cur = s.charAt(i);
            if (maxC == ' ') { // 初始字符
                maxC = cur;
                pre = i;
                maxStart = i;
            } else if (cur > maxC) {    // 字符更大，则直接从它开始
                maxStart = i;
                maxC = cur;
                pre = i;
            } else if (cur == maxC) {   // 相等的最大字符
                // 如果前一个最大字符与当前相差1，则直接跳过 处理 连续的情况
                if (pre + 1 == i) {
                    pre = i;
                    continue;
                }

                int m = maxStart + 1;
                int k;
                for (k = i + 1; k < s.length(); k++) {
                    if (s.charAt(k) > maxC) {   // 往后走的过程中遇到更大的字符
                        maxC = cur;
                        maxStart = k;
                        i = k;
                        break;
                    } else if (s.charAt(m) < s.charAt(k)) { // 当前最大字符开头的串更大
                        maxStart = i;
                        i = k;
                        break;
                    } else if (s.charAt(m) > s.charAt(k)) { // 比之前的更小
                        i = k;
                        break;
                    } else if (m >= i) {    // 如果比较到重叠位置，则停止
                        i = k - 1;
                        break;
                    }
                    m++;
                }
            }
        }
        return s.substring(maxStart);
    }
}
```
方法二 可以直接先找到最大字符的所有开始位置，然后获取最大字符串的开始位置。
```
public String lastSubstring1(String s) {
        if (s == null) {
            return "";
        }
        if (s.length() <= 1) {
            return s;
        }
        TreeSet<Integer> map = new TreeSet<>();
        char maxC = ' ';
        // 找出最大字符的所有开始位置
        for (int i = 0; i < s.length(); i++) {
            char cur = s.charAt(i);
            if (maxC == ' ') {
                maxC = cur;
                map.add(i);
            } else if (cur > maxC) {
                map.clear();
                map.add(i);
                maxC = cur;
            } else if (cur == maxC) {
                // 可以继续优化，处理下连续最大字符的情况，只加最开始的就可以。
                map.add(i);
            }
        }

        // 找出最字符开头的最大串
        if (map.size() == 1) {
            return s.substring(map.pollFirst());
        }
        int maxStart = map.pollFirst();
        int pre = maxStart;
        while (!map.isEmpty()) {
            int start = map.pollFirst();
            if (pre + 1 == start) {
                pre = start;
                continue;
            }
            int m = maxStart;
            for (int k = start + 1; k < s.length(); k++) {
                m++;
                if (s.charAt(m) < s.charAt(k)) {
                    maxStart = start;
                    break;
                } else if (s.charAt(m) > s.charAt(k)) {
                    break;
                }
            }
        }
        return s.substring(maxStart);
    }
```
