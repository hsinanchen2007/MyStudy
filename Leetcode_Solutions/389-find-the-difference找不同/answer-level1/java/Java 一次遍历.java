```
    public char findTheDifference(String s, String t) {
        int a = t.charAt(t.length()-1);
        for (int i = 0; i < s.length();i++){
            a =  (a ^ s.charAt(i));
            a = a ^ t.charAt(i);
        }
        return (char) a;
    }
```
