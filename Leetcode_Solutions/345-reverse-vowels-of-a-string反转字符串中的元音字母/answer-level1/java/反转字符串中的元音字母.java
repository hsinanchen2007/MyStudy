双指针的应用
```java
import java.util.*;
class Solution {
     private final static HashSet<Character> set = new HashSet<>(Arrays.asList('a','o','e','i','u','A','O','E','I','U'));
    public String reverseVowels(String s) {
        int i = 0,j = s.length()-1;
        char[] result = new char[s.length()];
        while(i<=j){
            char ci = s.charAt(i);
            char cj =s.charAt(j);
            if(!set.contains(ci)){
                result[i++] = ci;
            }else if(!set.contains(cj)){
                result[j--] = cj;
            }else{
                result[i++] = cj;
                result[j--] = ci;
            }
        }
        return new String(result);
    }
}
```