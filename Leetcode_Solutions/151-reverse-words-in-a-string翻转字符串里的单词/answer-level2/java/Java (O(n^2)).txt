### 解题思路
翻转一遍句子，然后对于每个单词再翻转一遍。

### 代码

```java
class Solution {
    public String reverseWords(String s) {
        // Reverse the whole line
        String res = "";
        List<Character> result = new ArrayList<Character>();
        s = s.trim();
        if (s == null || s.length() < 2){
            return s;
        }
        char previous_c = s.charAt(0);
        for (int i = s.length() - 1; i >= 0; i--){
            char c = s.charAt(i);
            if (c == ' ' && previous_c == ' '){
                continue;
            }
            previous_c = c;
            result.add(c);
        }

        // result : elpmaxe doog a
        String temp = "";
        for (int i = 0; i < result.size(); i++){
            if(result.get(i) != ' '){
                temp = temp + result.get(i);
            } else {
                res = res + reverseWord(temp) + " ";
                temp = "";
            }
        }
        
        res = res + reverseWord(temp);
        return res;
    }
    
    // reverse elpmaxe to example
    public String reverseWord(String s){
        String result = "";
        for (int i = s.length() - 1; i >= 0; i--){
            result = result + s.charAt(i);
        }
        return result;
    }
}
```