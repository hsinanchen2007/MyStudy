```
class Solution {
    public int longestPalindrome(String s) {
        if(s.length()<1) return 0;
        char[] ch=s.toCharArray();
        int[] temp=new int[58];
        int res=0;
        for(int i=0;i<ch.length;i++){
            temp[ch[i]-'A']++;
        }
        for(int i=0;i<58;i++){
            res+=temp[i]/2*2;
        }
        return res<ch.length?res+1:res;
    }
}
```
