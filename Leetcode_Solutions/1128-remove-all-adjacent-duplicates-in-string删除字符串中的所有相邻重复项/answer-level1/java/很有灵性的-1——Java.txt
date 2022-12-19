思路：挨个删除两个重复的字符即可。
<br/><br/>
代码：
```
class Solution {
    public String removeDuplicates(String S) {
        StringBuilder sb = new StringBuilder(S);
        deal(sb);
        
        return sb.toString();
    }
    
    private void deal(StringBuilder s) {
        for (int i = 0;i < s.length() - 1;i++) {
            if (s.charAt(i) == s.charAt(i + 1)) {
                s.deleteCharAt(i);
                s.deleteCharAt(i);
                i = -1;// 灵性的-1
            }
        }
    }
}
```