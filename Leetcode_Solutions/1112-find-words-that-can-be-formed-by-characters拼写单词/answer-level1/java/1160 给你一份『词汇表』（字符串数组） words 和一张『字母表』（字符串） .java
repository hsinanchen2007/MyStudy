### 解题思路
此处撰写解题思路
  * 1 注意：字符串的长度，通过题目范围取最大
     * 2.设置一个map保存可用字符和可用次数
     * 3.每次读取新单词时重置这个map,单词里的每个字符拿出来看map中是否存在，并且使用次数大于0，如果次数=0表示没有可以用的字符
     * 4.单词的每个字符都出现过，将值累计入count
### 代码

```java
class Solution {
 public int countCharacters(String[] words, String chars) {
        if (words == null || words.equals("")) {
            return 0;
        }
        int length = 0;

        for (int i = 0; i < words.length; i++) {
            String word = words[i];
            int appear = 0;
            Map<Character, Integer> flag = new HashMap<>();
            for (int j = 0; j < chars.length(); j++) {
                char c = chars.charAt(j);
                if (flag.containsKey(c)) {
                    flag.put(c, flag.get(c) + 1);
                } else {
                    flag.put(c, 1);
                }

            }
            char[] ws = word.toCharArray();
            for (int l = 0; l < ws.length; l++) {
                char letter = ws[l];
                if (flag.containsKey(letter) && flag.get(letter) > 0) {
                    //将状态值置为已经使用
                    flag.put(letter, flag.get(letter) - 1);
                    appear++;
                }
            }
            //一个单词都能拼出来
            if (appear == word.length()) {
                length += appear;
            }
        }
        return length;
    }

}
```