```
class Solution {
    public String reverseWords(String s) {
        //可以匹配多个空格
        String[] s1 = s.trim().split("\\s+");
        int len=s1.length;
        StringBuilder sb = new StringBuilder();
        for(int i=len-1;i>0;--i)
        {
            sb.append(s1[i]).append(" ");
        }
         sb.append(s1[0]);
        return sb.toString();
    }
}
```
