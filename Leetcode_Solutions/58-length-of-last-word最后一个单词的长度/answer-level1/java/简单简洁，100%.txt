执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :36.1 MB, 在所有 Java 提交中击败了61.94%的用户
```
class Solution {
    public int lengthOfLastWord(String s) {
        String S = s.trim();
        if (S.length() == 0)return 0;
        
        StringBuffer sb = new StringBuffer();
        for (int i = S.length() - 1; i >= 0; i--){
            if (S.charAt(i) == ' '){
                break;
            }
            sb.append(S.charAt(i));
        }
        return sb.toString().length();
    }
}
```

当然也有一种慢的思路。。。。
```
        String [] ans = s.split("\\s+");
         if (s.length() == 0||ans.length == 0)return 0;
        int len = ans[ans.length - 1].length();
         if (len>0)return len;
         return 0;
```

