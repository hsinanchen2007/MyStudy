### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean validPalindrome(String s) {
        int i = 0;
        int j = s.length() - 1;
        while(i <= j){
            if(i < j && s.charAt(i) == s.charAt(j)){
                i++;
                j--;
            }
            else if(isHuiwenchuan(s,i,j - 1) ||isHuiwenchuan(s,i+1,j)){
                return true;
            }
            else if(i != j)
                return false;
        }
        return true;
    }   

    public boolean isHuiwenchuan(String s, int start, int end){
        int i = start;
        int j = end;
        while(i < j){
            if(i < j && s.charAt(i) == s.charAt(j)){
                i++;
                j--;
            }
            else if(i != j)
                return false;
        }
        return true;
    }
}
```