### 解题思路
先判断字符串长度是否相等，然后按照字符进行快排，最后比较快排之后的字符数组组成的字符串是否相等。

### 代码

```java
class Solution {
   public boolean CheckPermutation(String s1, String s2) {
        if (s1.length() != s2.length()) {
            return false;
        }
        char[] arr1 = s1.toCharArray();
        char[] arr2 = s2.toCharArray();
        Arrays.sort(arr1);
        Arrays.sort(arr2);
        return Arrays.toString(arr1).equals(Arrays.toString(arr2));
    }
}
```