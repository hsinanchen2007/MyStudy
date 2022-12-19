### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        int strlength = astr.length();
        for(int i=0; i<strlength-1 ; i++) {
            char a = astr.charAt(i);
            for(int j=i+1;j<strlength; j++) {
                if(a == astr.charAt(j)) {
                    return false;
                }
            }
        }
        return true;
    }
}
```