```
class Solution {
    public int numberOfSubstrings(String s) {
        int ans=0;
        int[] abc=new int[3];
        for(int j=0,i=0;j<s.length();j++){
            char ch=s.charAt(j);
            abc[ch-'a']++;
            while(abc[0]>0&&abc[1]>0&&abc[2]>0){
                ch=s.charAt(i);
                ans+=s.length()-j;
                abc[ch-'a']--;
                i++;
            }
        }
        return ans;
    }
}
```
