### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isPalindrome(String s) {
        char[] c = s.toCharArray();
        int left=0;
        int right=s.length()-1;
        while(left<right){
            if(Character.isLetterOrDigit(c[left])&&Character.isLetterOrDigit(c[right])){
                if(c[left]==c[right]||
                (   Character.isLetter(c[left])&&
                    Character.isLetter(c[right])&&
                    Math.abs(c[left]-c[right])==32  )){ //大小写字母相差32 A：65 a:97
                    
                    left++;
                    right--;
                }else {return false;}          
            }else{
                if(!Character.isLetterOrDigit(c[left])) left++;
                if(!Character.isLetterOrDigit(c[right])) right--;
            }
        }
        return true;
    }
}
```