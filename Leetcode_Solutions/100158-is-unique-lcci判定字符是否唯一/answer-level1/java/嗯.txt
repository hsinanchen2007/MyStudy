### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        int[] arr = new int[26];
        for (int i = 0; i < astr.length(); i++) {
            int index = astr.charAt(i) - 97;
            if (arr[index] != 0) {
                return false;
            } else {
                arr[index]++;
            }
        }
        return true;
    }
}
```