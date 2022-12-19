### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isLongPressedName(String name, String typed) {
        if (name.length()>typed.length())return false;
        char[] c1 = name.toCharArray();
        char[] c2 = typed.toCharArray();

        int p1 = 0, p2 = 0;
        if (c1[0]!=c2[0])return false;
        while (p1 < c1.length && p2 < c2.length) {
            if (c1[p1] == c2[p2]) {
                p1++;
                p2++;
            }else if(c2[p2]==c2[p2-1]){
                p2++;
            }
            else return false;
        }
        return p1 == c1.length;
    }
}
```