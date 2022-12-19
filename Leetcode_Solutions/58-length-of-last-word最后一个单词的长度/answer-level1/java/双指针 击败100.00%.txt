### 解题思路
可以用双指针遍历，不需要trim或者split

### 代码

```java
class Solution {
    // 双指针
    public int lengthOfLastWord(String s) {
        int i = s.length() - 1;
        int j = s.length() - 1;
        while (j >=0) {
            // 尾部的空格i,j一起跳过
            if (s.charAt(j) == ' ' && i == j) {
                j--;
                i--;
            // 表示遍历完最后一个单词了
            } else if (s.charAt(j) == ' ' && i != j) {
                break;
            } else {
                // 遍历单词中
                j--;
            }
        }
        return i - j;
    }
}
```