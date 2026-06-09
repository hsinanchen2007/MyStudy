思路：先找出字符串末尾有多少个空格，然后再遍历

```java
class Solution {
    public int lengthOfLastWord(String s) {
        int l = s.length();
        int j = 0;
        
        int n = 0;
        for(int i = 0;i<l;i++){
            if(s.charAt(l-i-1)!=' '){
                break;
            }else{
                n++;
            }
        }
        if(n==l) return 0;
        
        
        for(int i = 0;i<l-n;i++){
            if(!(s.charAt(l-i-1-n)==' ')){
                j++;
            }else{
                break;
            }
        }
        return j;
    }
    
}
```
