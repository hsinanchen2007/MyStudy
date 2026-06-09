### 解题思路
最直观的解法是使用 HashMap 对出现次数进行统计，但是考虑到要统计的字符范围有限，因此可以使用整型数组代替 HashMap，从而将空间复杂度由 O(N) 降低为 O(1)。

### 代码

```java
class Solution {
   
    
    public char firstUniqChar(String s) {
        int[] cnts = new int[256];
        for (int i = 0; i < s.length(); i++)
            cnts[s.charAt(i)]++;
        for (int i = 0; i < s.length(); i++)
            if (cnts[s.charAt(i)] == 1)
                return s.charAt(i);
        return ' ';//注意char类型的返回值
    }

}
```