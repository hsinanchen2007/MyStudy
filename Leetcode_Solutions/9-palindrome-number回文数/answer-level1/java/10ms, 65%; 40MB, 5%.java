### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        if(x < 0)
            return false;
        String str = String.valueOf(x);
        int length = str.length();
        for(int i = 0; i <= length / 2 - 1; i++){
            if(str.charAt(i) != str.charAt(length - 1 - i))
                return false;
        }
        return true;
    }
}
```