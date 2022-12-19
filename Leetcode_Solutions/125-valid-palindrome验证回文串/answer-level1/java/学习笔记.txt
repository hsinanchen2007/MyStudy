思路如下：
先通过正则表达式处理字符串
然后循环比较
效率没那么高
```
class Solution {
    public boolean isPalindrome(String s) {
        int i;
        s = s.replaceAll("[^a-z^A-Z^0-9]", "");
        s =s.toLowerCase();
        i=s.length();
        for(int j=0;j<(i/2);j++){
            if(s.charAt(j)!=s.charAt(i-j-1)){
                return false;
            }
        }
        return true;
        
    }
}
```
