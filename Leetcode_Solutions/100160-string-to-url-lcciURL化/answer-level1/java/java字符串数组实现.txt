```
class Solution {
    public String replaceSpaces(String S, int length) {
        char[] ans = new char[length * 3];
        int idx = 0;
        for(int i = 0, len = length;i < len;i++){
            if(S.charAt(i) == ' '){
                ans[idx++] = '%';
                ans[idx++] = '2';
                ans[idx++] = '0';
            }else{
                ans[idx++] = S.charAt(i);
            }
        }
        return new String(ans, 0, idx);
    }
}
```
