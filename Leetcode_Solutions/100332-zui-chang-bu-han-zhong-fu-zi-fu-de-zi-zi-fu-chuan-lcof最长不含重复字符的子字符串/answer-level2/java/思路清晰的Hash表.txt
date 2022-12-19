### 解题思路
集美们，思路看代码注释噢~

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> map = new HashMap<>();
        // 不重复子串开始下标
        int start = 0;
        // 最长子串长度
        int max = 0;
        int i;
        for (i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);
            // 每一个字母和下标的映射都加入 hash 表
            Integer index = map.get(ch);
            if (index == null) {
                map.put(ch, i);
            }
            // 重复出现
            else {
                // 不在子串范围内
                if (start > index) {
                    // 更新字母最后一次出现的位置
                    map.put(ch, i);
                    continue;
                }
                max = (i - start > max) ? i - start : max;
                // 新子串开始下标为重复字母的下一个字母
                start = index + 1;
                map.put(ch, i);
            }
        }
        // 注意没有重复元素的情况
        return (i - start > max) ? i - start : max;
    }
}
```