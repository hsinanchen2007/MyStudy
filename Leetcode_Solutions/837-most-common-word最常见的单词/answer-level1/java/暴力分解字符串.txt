![image.png](https://pic.leetcode-cn.com/128cb715a7659f7e421d2695f3327357d2df11366152d65a621dd2d24894d504-image.png)

### 解题思路
遍历，遍历中获取单词，遇到非单词的持续遍历

### 代码

```java
class Solution {
    public String mostCommonWord(String paragraph, String[] banned) {
        Set<String> set = new HashSet<>(banned.length, 1);
        for (String string : banned) set.add(string);
        HashMap<String, Integer> map = new HashMap<>();

        String maxStr = null;
        int pre = 0, index = 0, max = 0;

        while (index < paragraph.length()) {
            if (paragraph.charAt(index) < 65) index++;
            else {
                pre = index;
                while (index < paragraph.length()) {
                    if (paragraph.charAt(index) < 65) break;
                    index++;
                }
                String str = paragraph.substring(pre, index).toLowerCase();
                if (set.contains(str)) continue;
                Integer count = map.get(str) == null ? 1 : map.get(str) + 1;
                map.put(str, count);
                if (count > max) {
                    maxStr = str;
                    max = count;
                }
            }
        }
        return maxStr;
    }
}
```