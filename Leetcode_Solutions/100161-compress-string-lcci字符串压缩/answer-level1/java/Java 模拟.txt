```java
class Solution {
    public String compressString(String S) {
        if(S.length() == 0) return "";
        int tmp;
        StringBuilder sb = new StringBuilder();
        int count = 1;
        sb.append(S.charAt(0));
        for(int i = 1;i < S.length();i++){
            if(S.charAt(i - 1) == S.charAt(i)){
                count ++;
            }else{
                sb.append(count).append(S.charAt(i));
                count = 1;
            }
        }
        sb.append(count);
        return sb.toString().length() < S.length()?sb.toString():S;
    }
}
```
