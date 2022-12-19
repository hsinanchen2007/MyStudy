### 解题思路
将每个单词生成的摩尔斯密码放入集合当中，返回集合中元素的个数即可。

### 代码

```java
import java.util.TreeSet;
class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        String[] codes = {".-","-...","-.-.","-..",".","..-.","--.","....","..",
                ".---","-.-", ".-..","--","-.","---",".--.","--.-",".-.","...",
                "-","..-","...-",".--","-..-", "-.--","--.."};
        TreeSet<String> set = new TreeSet<>();
        for (String word : words) {
            StringBuilder res = new StringBuilder();
            for (int i = 0 ; i < word.length() ; i ++) {
                res.append(codes[word.charAt(i) - 'a']);
            }
            set.add(res.toString());
        }
        return set.size();
    }
}
```