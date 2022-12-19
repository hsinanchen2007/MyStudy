### 解题思路
采用左右双指针，遍历一遍数组，遇到非数字或字母的j偏移指针。

### 代码

```java
class Solution {
    public boolean isPalindrome(String s) {
        int left = 0;
        int right = s.length()-1;
        while (right >= left){
            //遇到非数字或字母跳过
            if (!Character.isLetterOrDigit(s.charAt(left))){
                left++;
                continue;
            } 
            if (!Character.isLetterOrDigit(s.charAt(right))){
                right--;
                continue;
            } 
            //判断是否相等
            if (right >= left && Character.toLowerCase(s.charAt(left)) == Character.toLowerCase(s.charAt(right))) {
                left++;
                right--;
            }else return false;

            
        }
        return true;
    }
}
```