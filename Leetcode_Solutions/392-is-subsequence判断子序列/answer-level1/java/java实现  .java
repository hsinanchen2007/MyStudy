```
class Solution {
    public boolean isSubsequence(String s, String t) {
        int k = 0;//用于确保s中的每一个字符都是在t中按顺序出现的（按顺序进行比对）
        int flg = 0;//用于判断s字符串是否是t的字符串
        for(int i = 0 ; i < s.length() ; i++){
            for(int j = k ; j < t.length() ; j++){
                k++;
                if(s.charAt(i) == t.charAt(j)){//判断两个字符是否相等
                    flg++;
                    break;
                }
            }
        }
        if(flg == s.length()){
            return true;
        }else{
            return false;
        }  
    }
}
```
