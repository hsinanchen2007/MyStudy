- 设置左、右`双指针`，向中间判断；
- 跳过`非数字字母`的字符；
- 将字母全部转化为`小写体`，之后判断。
- `java`用了库函数，`python`纯自己实现（运行时间不太理想）。

```python []
class Solution:
    def isPalindrome(self, s: str) -> bool:
        left, right = 0, len(s) - 1
        case = abs(ord('a') - ord('A'))
        while left < right:
            while left < right and self.not_letters_digits(s[left]): left += 1
            while left < right and self.not_letters_digits(s[right]): right -= 1 
            s_l = ord(s[left]) - case if s[left] >= 'a' else ord(s[left])
            s_r = ord(s[right]) - case if s[right] >= 'a' else ord(s[right])
            if s_l != s_r: return False
            left += 1
            right -= 1
        return True
    
    def not_letters_digits(self, c):
        return not 'A' <= c <= 'Z' and not 'a' <= c <= 'z' and not '0' <= c <= '9'
```
```java []
class Solution {
    public boolean isPalindrome(String s) {
        int i = 0, j = s.length() - 1;
        while(i < j){
            while(i < j && !Character.isLetterOrDigit(s.charAt(i))) i++;
            while(i < j && !Character.isLetterOrDigit(s.charAt(j))) j--;
            if(Character.toLowerCase(s.charAt(i)) != Character.toLowerCase(s.charAt(j))) return false;
            i++; j--;
        }
        return true;
    }
}
```