```
class Solution {
    public String compressString(String S) {
        int oldLength = S.length();
        if(oldLength<=1){
            return S;
        }
        StringBuffer sb = new StringBuffer();
        char firstChar = S.charAt(0);
        int count = 1;
        for (int i = 1 ;i<oldLength ;i++){
            if(firstChar != S.charAt(i)){
                sb.append(firstChar).append(count);
                count = 1;
                firstChar = S.charAt(i);
            }else {
                count++;
            }
        }
        sb.append(firstChar).append(count);
        if(sb.length()>=oldLength){
            return S;
        }else {
            return sb.toString();
        }
    }
}
```
