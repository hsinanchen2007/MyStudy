![微信图片_20200221002952.png](https://pic.leetcode-cn.com/523b7de24ddba32a7c21c2e7fb38f4b64b5c550b049ceeb5c4db6ad4700953e4-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200221002952.png)

# 思路
最简单的想法就是统计26个字母各自出现的次数，得到一个大小为26的int数组。
关键在于如何将这个int数组转换为独一无二的key。
我的方法是将它转为String。
但肯定会有更好的转换法。

# 代码
```java
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        int len = strs.length;
        HashMap<String, List<String>> map = new HashMap<>(len);
        for (String str : strs) {
            int[] count = new int[26];
            int str_len = str.length();
            for (int i = 0; i < str_len; ++i)
                ++count[str.charAt(i) - 'a'];
            StringBuilder sb = new StringBuilder(100);
            for (int num : count)
                sb.append(num + '.');
            map.computeIfAbsent(sb.toString(), unused -> new LinkedList<>()).add(str);
        }
        return new ArrayList<>(map.values());
    }
}
```
