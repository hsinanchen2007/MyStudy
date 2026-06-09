### 解题思路
此处撰写解题思路
1. 不同的密码算一种解，所以结果需要去重，就考虑使用TreeSet
2. charAt(i)  System.out.println("jack".charAt(0));   //j
              System.out.println("jack".charAt(1));   //a
              System.out.println("jack".charAt(2));   //c
              System.out.println("jack".charAt(3));   //k
              System.out.println('j' - 'a');  //9


### 代码

```java
import java.util.TreeSet;

class Solution {

    String[] key={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

    public int uniqueMorseRepresentations(String[] words) {
        TreeSet<String> set = new TreeSet();
        for (String word : words) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < word.length(); i++) {
                sb.append(key[word.charAt(i)-'a']);
            }
            set.add(sb.toString());
        }

        return set.size();

    }

}
```