```
    public int lengthOfLastWord(String s) {

        char[] chars = s.toCharArray();
        if(chars.length==0){
            return 0;
        }
        boolean isFindChar = false;
        int count = 0;
        for (int i = 0; i < chars.length; i++) {
            if(chars[chars.length-1-i]!=' '){
                count++;
                isFindChar=true;
            }else {
                if(isFindChar){
                    return count;
                }
            }
        }
        return count;
    }
```
