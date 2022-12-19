采用双指针，一个低指针，一个高指针，低指针逐渐增加，高指针逐渐降低，如果两个指针的内容不相同时，将高指针减一或者高指针加一，即将原字符串删除一个字母（最左或者最右）， 之后再次判断新的字符串是否是回文字符串，即与前述方法相同，低指针向高处移动，高指针向低处移动，如果遇到不相同的字母则之间返回false,否则返回true.
### 代码

```java
class Solution {
    public boolean validPalindrome(String s) {
        int i = 0, j = s.length() - 1;
        while(i < j){
            if(s.charAt(i)!= s.charAt(j)){
                return isPalindrome(s, i, j - 1) || isPalindrome(s, i + 1, j);
            }
            i++;j--;
        }
        return true;
    }
    private boolean isPalindrome(String s, int i, int j){
        while(i < j){
            if(s.charAt(i++)!=s.charAt(j--)){
                return false;
            }
        }
        return true;
    }
}
```