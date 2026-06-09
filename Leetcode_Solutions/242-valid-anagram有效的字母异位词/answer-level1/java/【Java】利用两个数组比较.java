### 解题思路
针对s创建arrayForS数组；t创建arrayForT数组。
这两个数组长度为26的数组，记录字符串中各字母的数量（所以为int型的）。
比较两个数组的内容是否相等。
注意：{用Arrays.equlas(string1, string2)比较内容，“==”比较的是两个对象在内存中的首地址}。

### 代码

```java
class Solution {
    public boolean isAnagram(String s, String t) {

        int[] arrayForS = new int[26]; // 字符串s的数组
        int[] arrayForT = new int[26]; // 字符串t的数组
        for (char char1 : s.toCharArray()) {

            arrayForS[char1 - 'a']++;
        }
        for (char char2 : t.toCharArray()) {

            arrayForT[char2 - 'a']++;
        }
        return Arrays.equals(arrayForS, arrayForT);
    }
}
```