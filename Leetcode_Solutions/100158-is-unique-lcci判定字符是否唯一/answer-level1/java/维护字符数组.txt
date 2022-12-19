### 解题思路
128长的字符数组

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        int n = astr.length();
        int[] strList = new int[128];
        for (int i=0;i<n;i++) {
            strList[astr.charAt(i)] = strList[astr.charAt(i)]+1;
            if (strList[astr.charAt(i)]>1) {
                return false;
            }
        }
        return true;
    }
}
```