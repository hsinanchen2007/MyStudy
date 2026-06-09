### 解题思路
借助于一个大小为256的int数组来协助！！！

### 代码

```java
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        if (s1 == null && s2 == null) {
            return true;
        }
        if (s1 == null || s2 == null) {
            return false;
        }
        if (s1.length() != s2.length()) {
            return false;
        }

        int[] array = new int[256];
        for (int i = 0; i < s1.length(); i++) {
            array[s1.charAt(i)]++;
        }
        for (int i = 0; i < s2.length(); i++) {
            array[s2.charAt(i)]--;
        }
        for (int i = 0; i < 256; i++) {
            if (array[i] != 0) {
                return false;
            }
        }
        return true;
    }
}
```