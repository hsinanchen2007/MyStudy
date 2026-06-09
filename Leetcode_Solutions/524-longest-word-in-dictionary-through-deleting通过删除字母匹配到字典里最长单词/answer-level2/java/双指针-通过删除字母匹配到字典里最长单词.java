遍历字符数组d，如果遇到数组比已匹配数组长度大时，来判断是否能够通过s匹配成功，匹配的方法是采用双指针，一个指针指向s，一个指针指向待匹配字符串，如果此时指针指向的字母相等，则将两个指针同时移动，否则只移动指向s的指针，最后如果匹配成功，指向待匹配字符的指针应该会移动到字符串的末尾，返回boolean则可以判断，如果匹配成功，将longword赋值为该值，继续遍历。
### 代码

```java
class Solution {
    public String findLongestWord(String s, List<String> d) {
        String longword = "";
        for(String word: d){
            int l1 = longword.length(), l2 = word.length();
            if(l1 > l2 || (l1 == l2 && longword.compareTo(word) < 0)){
                continue;
            }
            if(isSubstr(s, word)){
                longword = word;
            }
        }
        return longword;
    }
    private boolean isSubstr(String s, String word){
        int i = 0, j = 0;
        while(i < s.length() && j < word.length()){
            if(s.charAt(i) == word.charAt(j)){
                j++;
            }
            i++;
        }
        return j == word.length();
    }
}
```