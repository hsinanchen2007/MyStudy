```java
class Solution {
    public List<Integer> partitionLabels(String S) {
        // 计算并存储每个字符在数组中所在的最大索引
        int[] c2Index = new int[26];
        for (int i = 0; i < S.length(); i++) {
            c2Index[S.charAt(i) - 'a'] = i;
        }

        // 存储最终结果
        List<Integer> res = new ArrayList<>();

        // 维护窗口
        int left = 0;
        int right = 0;
        for (int i = 0; i < S.length(); i++) {
            // 计算窗口的右指针
            right = Math.max(right, c2Index[S.charAt(i) - 'a']);

            // left 指针移动到右指针的下一位
            // 移动时机：当再一次遇到右指针索引位置
            // 移动策略：计算一个片段的长度
            if (i == right) {
                res.add(right - left + 1);
                left = right + 1;
            }
        }

        return res;
    }
}
```