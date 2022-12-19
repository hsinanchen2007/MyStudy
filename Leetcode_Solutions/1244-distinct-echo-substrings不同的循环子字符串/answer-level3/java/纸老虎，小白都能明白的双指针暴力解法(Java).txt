```
class Solution {
    public int distinctEchoSubstrings(String text) {
        Set<String> set = new HashSet<>();
        int len = text.length();
        String temp = "";
        // two pointers
        for (int x = 0;x < len - 1;x ++)
            for (int y = x + 1;y < len;y = y + 2) {// key point
                temp = text.substring(x,y + 1);
                if (isDoubleStr(temp))
                    set.add(temp); // 去重
            }
        return set.size();
    }

     // ensure s.length() is even number
    public  boolean isDoubleStr(String s){
        int len = s.length();
        int middle = len / 2;
        return s.substring(0,middle).equals(s.substring(middle));
    }
}
```
