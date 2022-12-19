执行用时 : 6 ms, 击败了75.22% 的用户.
内存消耗 : 49.2 MB, 击败了95.23% 的用户.
```
class Solution {
    public boolean isSubsequence(String s, String t) {
        char[] chars = s.toCharArray();
        int index = 0;
        for(int i = 0; i < chars.length; i++){
            int k = t.indexOf(String.valueOf(chars[i]),index);
            if(k<0){
                return false;
            }
            index = k + 1;
        }
        return true;
    }
}
```