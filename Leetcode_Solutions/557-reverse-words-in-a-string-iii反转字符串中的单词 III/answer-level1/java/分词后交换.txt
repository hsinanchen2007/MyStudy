```
class Solution {
    public String reverseWords(String s) {
        Solution so = new Solution();
        char[] ch = s.toCharArray();
        String s1[] = s.split(" ");
        StringBuilder sb = new StringBuilder();
        int i;
        for(i = 0;i < s1.length;i++){
            String s2 = so.rever(s1[i]);
            sb.append(s2);
            if(i != s1.length - 1)
                sb.append(" ");
        }
        return sb.toString();
    }
    public String rever(String s){
        char t = '0';
        char[] ch = s.toCharArray();
        int i = 0,j = ch.length - 1;
        while(i <= j){
            t = ch[j];
            ch[j] = ch[i];
            ch[i] = t;
            i++;
            j--;
        }
        return String.valueOf(ch);
    }
}
```
