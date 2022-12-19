### 解题思路
我真的快要气死了 微笑脸
本来好好的，分词嘛，谁不会，官方解答也说可以先按照空格分词，然后移除标点符号并忽略大小写；
可以，你给我一个这种测试用例："a, a, a, a, b,b,b,c, c"，词和词之间空格都没有，到头来还得按部就班通过判断每个 char 是否是字母来分词，心碎

### 代码

```java
class Solution {
    public String mostCommonWord(String paragraph, String[] banned) {
        paragraph+=".";
        Set<String> banset = new HashSet();
        for (String word: banned) banset.add(word);
        Map<String, Integer> count = new HashMap();

        String ans = "";
        int ansfreq = 0;

        StringBuilder word = new StringBuilder();
        for (char c: paragraph.toCharArray()) {
            if (Character.isLetter(c)) {
                word.append(Character.toLowerCase(c));
            } else if (word.length() > 0) {
                String finalword = word.toString();
                if (!banset.contains(finalword)) {
                    count.put(finalword, count.getOrDefault(finalword, 0) + 1);
                    if (count.get(finalword) > ansfreq) {
                        ans = finalword;
                        ansfreq = count.get(finalword);
                    }
                }
                word = new StringBuilder();
            }
        }

        return ans;
    }
}
```