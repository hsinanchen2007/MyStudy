```
class Solution {
    public boolean checkRecord(String s) {
        if(s == null || s.length() == 0) return false;
        char[] ch = s.toCharArray();
        int a = 0;
        int l = 0;
        for(int i = 0; i < ch.length;i++){
            if(ch[i] == 'A')
                a++;
        }
        if(s.contains("LLL"))
            l = 1;
        if(a <= 1 && l == 0)
            return true;
        else 
            return false;
    }
}
```
