```
/*
    执行用时 :14 ms, 在所有 Java 提交中击败了98.67% 的用户
    内存消耗 :38.3 MB, 在所有 Java 提交中击败了97.50%的用户
*/
class Solution {
    public int numUniqueEmails(String[] emails) {
        Set<String> set = new HashSet<>();
        for (String s : emails) {
            int indexa = 0;
            boolean flag = false;
            
            StringBuilder key = new StringBuilder() ;
            for (int i = 0; i < s.length(); i++) {
                char c = s.charAt(i);
                if (c == '@') {
                    indexa = i;
                    break;
                }
                if (flag | c == '.'){
                    continue;
                }
                if (c == '+') {
                    flag = true;
                    continue;
                }
                key.append(c);
            }
            key.append(s.substring(indexa, s.length()));
            
            
            set.add(key.toString());
        }
        
        return set.size();
    }
}
```
