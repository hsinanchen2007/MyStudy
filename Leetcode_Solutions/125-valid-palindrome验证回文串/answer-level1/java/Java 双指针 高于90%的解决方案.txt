尽可能少地去调用库函数，太耗费性能了~
```
public boolean isPalindrome(String s) {
        char[] chars = s.toCharArray();
        for (int i=0,j=chars.length-1; i<j;) {
            if (!(Character.toLowerCase(chars[i]) >= 'a' && Character.toLowerCase(chars[i]) <= 'z')
                    && !(chars[i] >= '0' && chars[i] <= '9')) {
                i++;
                continue;
            }
            if (!(Character.toLowerCase(chars[j]) >= 'a' && Character.toLowerCase(chars[j]) <= 'z')
                    && !(chars[j] >= '0' && chars[j] <= '9')) {
                j--;
                continue;
            }
            if (Character.toLowerCase(chars[i]) != Character.toLowerCase(chars[j])) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
```