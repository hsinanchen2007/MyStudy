### 解题思路


### 代码

```java
class Solution {
    public void reverseString(char[] s) {
         int i = 0;
        int h = s.length-1;
        while (i <= h){
            char temp = s[i];
            s[i] = s[h];
            s[h] = temp;
            i++;
            h--;
        }

    }
}
```