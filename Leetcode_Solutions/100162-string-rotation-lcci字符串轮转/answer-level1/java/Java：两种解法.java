```
class Solution {
    public boolean isFlipedString(String s1, String s2) {
        if(s1.length() != s2.length())
            return false;
        s1 += s1;
        return s1.contains(s2);
    }
}
```

```
class Solution {
    public boolean isFlipedString(String s1, String s2) {
        if(s1.length() != s2.length())
            return false;
        if(s1.equals(s2))
            return true;
        StringBuilder sb = new StringBuilder();
        for(int i = 1; i < s1.length(); i++){
            sb.append(s1.substring(i, s1.length())).append(s1.substring(0, i));
            if(sb.toString().equals(s2)){
                return true;
            }
            sb.delete(0, s1.length());
        }
        return false;
    }
}
```

