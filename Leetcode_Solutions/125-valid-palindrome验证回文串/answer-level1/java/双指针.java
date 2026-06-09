### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isPalindrome(String s) {
       if(s==null||s.length()==0)
        return true;
    
        int p1 = 0;
        int p2 =s.length()-1;

        while (p1<=p2) {
            while(p1<s.length()&&!Character.isLetterOrDigit(s.charAt(p1)))
                p1++;
        
            while(p2>=0&&!Character.isLetterOrDigit(s.charAt(p2)))
                p2--;
            if(p1<=p2){

                if(Character.toLowerCase(s.charAt(p1)) != Character.toLowerCase(s.charAt(p2))) return false;
                p1++;
                p2--;
            }
        }

            return true;

    }
}
```