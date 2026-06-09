### 执行结果

执行用时 :**3 ms**, 在所有 Java 提交中击败了 **95.01%** 的用户
内存消耗 :**36.1 MB**, 在所有 Java 提交中击败了 **87.00%** 的用户

### 解题思路

1. 记录每个字母在S中最后出现的下标
2. 从下标0开始尝试分段，左边界left是0
3. “同一个字母必须在同一片段中”,所以初始right是该段首字母最后出现的位置
4. 动态遍历left到right，如果有字符最后出现的下标大于right，更新right
5. 遍历完成后，一个分段就生成了。计数区间长度，更新left = right + 1，转3继续。

### 代码

```java
class Solution {
    public List<Integer> partitionLabels(String S) {
        if (null == S || 0 == S.length()) {
            return null;
        }
        int len = S.length();

        // 做映射表，记录每个字母最后出现的位置
        int[] ma = new int[26];
        for (int i = 0; i < len; ++i) {
            ma[S.charAt(i) - 'a'] = i;
        }

        List<Integer> ans = new ArrayList<>();
        int left = 0;
        while (left < len) {
            char curLeft = S.charAt(left);
            // 最小右边界
            int right = ma[curLeft - 'a'];
            for (int i = left + 1; i < right; ++i) {
                // 枚举当前分段中的字符，更新右边界
                if (ma[S.charAt(i) - 'a'] > right) {
                    right = ma[S.charAt(i) - 'a'];
                }
            }
            // 至此，一个新的片段生成了
            ans.add(right - left + 1);
            // 分析下一段
            left = right + 1;
        }
        return ans;
    }
}
```