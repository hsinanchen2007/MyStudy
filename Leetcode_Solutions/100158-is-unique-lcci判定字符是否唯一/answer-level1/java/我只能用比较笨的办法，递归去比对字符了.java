### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
     public boolean isUnique(String astr) {
        char[] chars = astr.toCharArray();
        int index = 0;
        while (index < chars.length - 1) {
            if (circle(index, chars)) {
                index++;
            } else {
                return false;
            }
        }

        return true;
    }

    public boolean circle(int index, char[] chars) {
        if (index < chars.length - 1) {
            for (int i = index; i < chars.length-1; i++) {
                if (chars[index] == chars[i+1]) {
                    return false;
                }
            }
        }
        return true;
    }
}
```