```java
class Solution {
    private String digits;
    private int len;
    private int curlen = -1;
    private List<String> list = new ArrayList<>(); 
    private StringBuilder sb = new StringBuilder();
    private char[][] map = new char[8][];
    {
        map[0] = new char[] {'a', 'b', 'c'};
        map[1] = new char[] {'d', 'e', 'f'};
        map[2] = new char[] {'g', 'h', 'i'};
        map[3] = new char[] {'j', 'k', 'l'};
        map[4] = new char[] {'m', 'n', 'o'};
        map[5] = new char[] {'p', 'q', 'r', 's'};
        map[6] = new char[] {'t', 'u', 'v'};
        map[7] = new char[] {'w', 'x', 'y', 'z'};
    }
    
    public List<String> letterCombinations(String digits) {
        len = digits.length();
        if(len == 0) return new ArrayList<>();
        this.digits = digits;
        helper(0);
        return list;
    }
    
    public void helper(int i) {
        if(i == len) {
            list.add(sb.toString());
            return;
        }
        
        for(char c : map[digits.charAt(i) - '2']) {
            sb.append(c);
            curlen++;
            helper(i + 1);
            sb.deleteCharAt(curlen);
            curlen--;
        }
    }
    
}
```
