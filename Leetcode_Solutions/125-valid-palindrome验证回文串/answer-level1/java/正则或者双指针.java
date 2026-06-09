## 思路:

思路一: 用正则提取字母和数字字符, 在取反比较

思路二: 双指针

## 代码:

思路一:

```python [1]
def isPalindrome(self, s: str) -> bool:
        tmp = re.sub(r"[^A-Za-z0-9]","", s).lower()
        return tmp == tmp[::-1]
```



```java [1]
class Solution {
    public boolean isPalindrome(String s) {
        String tmp = s.replaceAll("[^A-Za-z0-9]", "").toLowerCase();
        String rev_tmp = new StringBuffer(tmp).reverse().toString();
        return tmp.equals(rev_tmp);
    }
}
```

思路二:

```python [2]
def isPalindrome(self, s: str) -> bool:
        n = len(s)
        left = 0
        right = n - 1
        while left < right:
            while left < right and not s[left].isalnum():
                left += 1
            while left < right and not s[right].isalnum():
                right -= 1
            if s[left].lower() != s[right].lower():
                return False
            left += 1
            right -= 1
        return True
```

```java [2]
class Solution {
    public boolean isPalindrome(String s) {
        char[] c = s.toCharArray();
        int left = 0;
        int right = c.length - 1;
        while (left < right) {
            while (left < right && !Character.isLetterOrDigit(c[left])) left++;
            while (left < right && !Character.isLetterOrDigit(c[right])) right--;
            if (Character.toLowerCase(c[left]) != Character.toLowerCase(c[right])) return false;
            left++;
            right--;
        }
        return true;
    }
}
```

