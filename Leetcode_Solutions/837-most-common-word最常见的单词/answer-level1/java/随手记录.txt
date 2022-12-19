### 解题思路
这是一个简单但很麻烦的题。对于初学者来说，此题可以快速熟悉Java常见集合类型和字符串处理。我最开始的思路很蠢:想要把字符串paragraph遍历一遍处理成小写的且没有banned数组单词的集合a，然后再遍历a,生成一个带计数的表b,最后再遍历b，找到计数值最大的单词。然而这个思路需要遍历三次目标对象且是不同的数据结构（String，ArrayList, HashMap）其实挺麻烦的。

然而实际操作时，可以只遍历一次：遍历字符串paragraph的每个字符，只要是字母就继续读取并缓存到sb，直到形成第一个单词res，检查这个单词是否属于黑名单banned，如果不属于则放入哈希表hm里并计数，并比较当前哈希表的计数与历史最高max的值大小，如果更多则把当前放入哈希表的单词res设为最高计数max对应的单词result。一个单词处理完后，清空sb。遍历完成后，输出result.
为了保证paragraph最后一个字符遍历完成后也能当作单词处理，给paragraph追加一个'.'。
为了实现黑名单功能，可以把数组转成HashSet或者直接使用Arrays.asList(数组).contains(元素)。

### 代码

```java
class Solution {
    public String mostCommonWord(String paragraph, String[] banned) {
        paragraph += ".";

        HashSet<String> hs = new HashSet<>();
        for (String ban : banned) hs.add(ban.toLowerCase());

        HashMap<String, Integer> hm = new HashMap<>();
        int max = 0;
        String result = "";
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < paragraph.length(); i++) {
            char c = paragraph.charAt(i);
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
                sb.append(c);
                continue;
            }
            if (sb.length() > 0) {
                String res = sb.toString().toLowerCase();
                if (!hs.contains(res)) {
                    hm.put(res, hm.getOrDefault(res, 0) + 1);
                    int count = hm.get(res);
                    if (count > max) {
                        max = count;
                        result = res;
                    }
                }
                sb = new StringBuilder();
            }
        }
        return result;
    }
}
```