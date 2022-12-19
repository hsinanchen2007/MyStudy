```java
class Solution {
    public boolean isScramble(String s1, String s2) {
        if(s1.length()==1&&s2.length()==1&&s1.equals(s2))
            return true;
        else if (s1.length()==1&&s2.length()==1&&(!s1.equals(s2)))
            return false;
        if (s1.length()!=s2.length())
            return false;
        if (!equals(s1.toCharArray(),s2.toCharArray(),0,0,s1.length()))
            return false;
        if(s1.equals(s2))
            return true;

        for (int i=1;i<s1.length();i++){
            if (
                    (isScramble(s1.substring(0,i),s2.substring(0,i))&&isScramble(s1.substring(i,s1.length()),s2.substring(i,s2.length())))||
                    (isScramble(s1.substring(0,i),s2.substring(s2.length()-i,s2.length()))&&isScramble(s1.substring(i,s1.length()),s2.substring(0,s2.length()-i)))
            )
                return true;
        }
        return false;
    }


    public boolean equals(char[] s1, char[] s2, int start1, int start2, int len){  //尽量减小递归深度
        int[] charArr = new int[26];
        for (int i=0; i<len; i++) {
            charArr[s1[start1+i] - 'a']++;
            charArr[s2[start2+i] - 'a']--;
        }
        for (int item : charArr) {
            if (item != 0) return false;
        }
        return true;
    }
}    
```
