### 解题思路
Character.isLetterOrDigit 判断是否是字符或者数字

### 代码

```java
class Solution {
    public boolean isPalindrome(String s) {
  char[] cha = s.toCharArray();
        int i = 0, j = cha.length - 1;
        while(i < j){
            if(!Character.isLetterOrDigit(cha[i]))
                i++;
            else if(!Character.isLetterOrDigit(cha[j]))
                j--;
            else
                if(Character.toLowerCase(cha[i]) == Character.toLowerCase(cha[j])){
                    i++;
                    j--;
                }else{
                    return false;
                }
        }
        return true;

    }
}
```