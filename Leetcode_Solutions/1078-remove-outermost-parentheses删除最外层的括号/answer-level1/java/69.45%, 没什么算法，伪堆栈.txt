```
class Solution {
    public String removeOuterParentheses(String S) {
        // 先分解再拆
        StringBuffer sb = new StringBuffer();
        int c = 0, s = 0;
        for(int i = 0; i < S.length(); ++ i) {
            if(S.charAt(i) == '(')
                c ++;
            else
                c --;
            if(c == 0) {
                //System.out.println("chose " + S.substring(s, i + 1));
                sb.append(strip(S.substring(s, i + 1)));
                s = i + 1;
            }
        }
        return sb.toString();
    }

    private String strip(String s) {
        return s.substring(1, s.length() - 1);
    }
}
```
