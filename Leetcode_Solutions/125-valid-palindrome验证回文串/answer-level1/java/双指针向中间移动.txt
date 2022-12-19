执行结果：
通过
显示详情
执行用时 :
8 ms
, 在所有 Java 提交中击败了
89.77%
的用户
内存消耗 :
39.2 MB
, 在所有 Java 提交中击败了
51.67%
的用户
```
class Solution {
    public boolean isPalindrome(String s) {
        int len = s.length();
        if(len==0||len==1)return true;
        int i=0;
        int j=len-1;
        while(i<j){
            char a = s.charAt(i);
           
            if(!valid(a)){
                i++;
                continue;
            } 
            
             char b = s.charAt(j);
             if(!valid(b)){
                j--;
                continue;
            } 
            if(!equ(a,b)){
                return false;
            }else{
                i++;
                j--;
            }
        }
        return true;
    }
    private boolean valid(char c){
        if(c>='a'&&c<='z'||c>='A'&&c<='Z'||c>='0'&&c<='9'){
            return true;
        }else{
            return false;
        }
    }
    private boolean equ(char a, char b){
        if(a==b)return true;
        if(a>='a'&&a<='z'){
            if(b-a=='A'-'a'){
                return true;
            }
        }else if(b>='a'&&b<='z'){
            if(b-a=='a'-'A'){
                return true;
            }
        }
        return false;
    }
}
```
