```java []
class Solution {
    public String compressString(String S) {
        if(S == null){
            return "";
        }
        if(S.length() == 1){
            return S;
        }
        int N = S.length();
        int i = 0;
        StringBuilder sb = new StringBuilder();
        while(i < N){
            int j = i;
            while(j < N && S.charAt(j) == S.charAt(i)){
                j++;
            }
            sb.append(S.charAt(i));
            sb.append(j - i);
            i = j;
        }

        String res = sb.toString();
        if (res.length() < S.length()) {
            return res;
        } 
        else 
        {
        return S;
        }
    }
}