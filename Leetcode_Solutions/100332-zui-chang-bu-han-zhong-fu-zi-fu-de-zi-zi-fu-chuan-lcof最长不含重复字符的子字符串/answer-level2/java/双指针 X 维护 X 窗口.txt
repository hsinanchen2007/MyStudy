
```
class Solution {
    public int lengthOfLongestSubstring(String s) {
        if(s==null || s.equals("")) return 0;
        char[] c = s.toCharArray();
        char[] record = new char[128];
        int max=0, n=c.length;
        for(int p=0,q=0; p<n && q<n; ){
            if(record[c[q]]==0){
                record[c[q++]]++;
                max=max>(q-p)?max:(q-p);
            }else{
                record[c[p++]]--;
            }
        }
        return max;
    }
}
```
