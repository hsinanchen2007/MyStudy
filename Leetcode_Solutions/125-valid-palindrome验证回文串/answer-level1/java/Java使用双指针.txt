```java
    private boolean isNumORChar(char c){
        if ((c>='a' && c<='z') || (c>='0' && c<='9')){
            return true;
        }
        return false;
    }

    public boolean isPalindrome(String s) {
        if (s==null || s.length()==0){
            return true;
        }
        char[] chs=s.toLowerCase().toCharArray();
        int i=0;
        int j=s.length()-1;
        while (i<j){
            while (!isNumORChar(chs[i]) && i<j){
                i++;
            }

            while (!isNumORChar(chs[j]) && i<j){
                j--;
            }
            if (chs[i]==chs[j]){
                i++;
                j--;
            }else {
                return false;
            }
        }
        return true;
    }
```
