![image.png](https://pic.leetcode-cn.com/5bfac30f8535870b6f3408e4b8d796ab515f753e766b8b4ed154344019f15691-image.png)
```
import java.util.HashSet;
import java.util.Set;

public class toGoatLatin {
    class Solution {
        Set<Character> set = new HashSet<>();
        public String toGoatLatin(String S) {
            String[] strings = S.split(" ");
            StringBuilder sb = new StringBuilder();
            char[] chars = {};
            set.add('a');
            set.add('e');
            set.add('i');
            set.add('o');
            set.add('u');
            set.add('A');
            set.add('E');
            set.add('I');
            set.add('O');
            set.add('U');
            for (int i = 0; i <strings.length ; i++) {
                String s = operation(strings[i]);
                sb.append(s);
                for (int j = 0; j <i+1 ; j++) {
                    sb.append("a");
                }
                sb.append(" ");
            }
            sb.delete(sb.length()-1,sb.length());
            return sb.toString();
        }

        private String operation(String string) {
            char[] chars = string.toCharArray();
            if (!set.contains(chars[0])){//辅音开头
                char first = chars[0];
                for (int i = 1; i <chars.length ; i++) {
                    chars[i-1] = chars[i];
                }
                chars[chars.length-1]=first;
            }
            StringBuilder sb = new StringBuilder();
            sb.append(chars);
            sb.append("ma");
            return sb.toString();
        }
    }
}
```
