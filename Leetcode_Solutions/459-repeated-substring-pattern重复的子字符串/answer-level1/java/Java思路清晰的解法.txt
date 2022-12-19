执行用时 :17 ms, 在所有 Java 提交中击败了87.04%的用户    
内存消耗 :37.9 MB, 在所有 Java 提交中击败了38.75%的用户    
```
class Solution {
    public boolean repeatedSubstringPattern(String s) {
        for(int i=1;i<s.length();i++){
            if(s.length()%i==0){
                if(judge(s.substring(0,i),s)) return true;
            }
        }
        return false;
    }
    public boolean judge(String sub, String S){
        int len = sub.length();
        for(int i=0;i<S.length();i++){
            if(S.charAt(i)!=sub.charAt(i%len)) return false;
        }
        return true;
    }
}
```