```
class Solution {
    public boolean isPalindrome(String s) {
        if(s == null || s.length() <= 0) return true;
        int startInt = -1;
        int endInt = -1;
        for(int i = 0, j = s.length()-1; i < s.length();) {
            //只要符合的字母数字，同步将大写转小写
            while((startInt = getValid(s.charAt(i))) < 0) {
                i++;
                if(i >= j) return true;
            }
            while((endInt = getValid(s.charAt(j))) < 0) {
                j--;
                if(i >= j) return true;
            }

            if(i < j) {
                i++;j--;
                //只要在i<j时，不相等即跳出为false，否则为true；
                if(startInt != endInt) return false;
            }else {
                return true;
            }
        }
        return true;
    }

    private int getValid(char c) {
        if(c >= 65 && c <= 90) {
            return c+32;
        }else if((c >= 48 && c <= 57) || (c >= 97 && c <= 122)) {
            return c;
        }else return -1;
    }
}
```
