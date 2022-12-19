![奇怪的知识增加了.jpg](https://pic.leetcode-cn.com/382ef0705ccfa22bbcbec5d9a2251596331a61ad51cfdd27fdf3fae6a57eeadb-%E5%A5%87%E6%80%AA%E7%9A%84%E7%9F%A5%E8%AF%86%E5%A2%9E%E5%8A%A0%E4%BA%86.jpg)


### 代码

```java
class Solution {
    public int minimumLengthEncoding(String[] words) {
        // 按长度的降序排列
        Arrays.sort(words, (String s, String t1) -> t1.length() - s.length());
        // 看看后面的字符串是否在前面出现过，并且是之前的出现过的尾部
        StringBuffer sb = new StringBuffer();
        sb.append(words[0] + "#");
        for (int i = 1; i < words.length; i++) {
            if (sb.indexOf(words[i] + "#") < 0) {// 没出现在之前的末尾
                sb.append(words[i] + "#");
            }
        }
        return sb.length();
    }
}
```