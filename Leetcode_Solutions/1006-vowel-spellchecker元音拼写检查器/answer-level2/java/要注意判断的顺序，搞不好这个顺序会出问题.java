### 解题思路
参见注释

### 代码

```java
class Solution {
    public String[] spellchecker(String[] wordlist, String[] queries) {
        Set<String> equals = new HashSet<>();
        Map<String, String> lowerEqual = new HashMap<>();
        Map<String, String> vowelEqual = new HashMap<>();

        for (int i = 0; i < wordlist.length; i++) {
            equals.add(wordlist[i]);
            //为什么用这个 putIfAbsent ，因为这个判断已有了之后不再新加覆盖。为了满足题目要求：第一个这样的匹配项。
            lowerEqual.putIfAbsent(wordlist[i].toLowerCase(), wordlist[i]);
            vowelEqual.putIfAbsent(getVowel(wordlist[i]), wordlist[i]);
        }
        String[] results = new String[queries.length];

        int index = 0;
        for (int i = 0; i < queries.length; i++) {
            //完全相等
            if (equals.contains(queries[i])) {
                results[index++] = queries[i];
            } else if (lowerEqual.containsKey(queries[i].toLowerCase())) {
                //大小写相等
                results[index++] = lowerEqual.get(queries[i].toLowerCase());
            } else if (vowelEqual.containsKey(getVowel(queries[i]))) {
                //元音相同
                results[index++] = vowelEqual.get(getVowel(queries[i]));
            } else {
                //不匹配
                results[index++] = "";
            }
        }
        return results;
    }

    private String getVowel(String s) {
        StringBuffer stringBuffer = new StringBuffer();
        for (char ch : s.toCharArray()) {
            //如果碰到元音字符用*代替
            if (isVowel(ch)) {
                stringBuffer.append("*");
            } else {
                stringBuffer.append(Character.toLowerCase(ch));
            }
        }
        return stringBuffer.toString();
    }

    private boolean isVowel(char charAt) {
        return Character.toLowerCase(charAt) == 'a'
                || Character.toLowerCase(charAt) == 'e'
                || Character.toLowerCase(charAt) == 'i'
                || Character.toLowerCase(charAt) == 'o'
                || Character.toLowerCase(charAt) == 'u';
    }
}
```