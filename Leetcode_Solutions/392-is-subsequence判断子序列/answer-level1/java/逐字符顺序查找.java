```
    public boolean isSubsequence(String s, String t) {
        boolean isSubSeq = true;

        int index = 0;
        for (int i = 0; i < s.length(); i++) {
            index = t.indexOf(s.charAt(i), index);
            if (index == -1){
                isSubSeq = false;
                break;
            }

            index++;
        }

        return isSubSeq;
    }
```
