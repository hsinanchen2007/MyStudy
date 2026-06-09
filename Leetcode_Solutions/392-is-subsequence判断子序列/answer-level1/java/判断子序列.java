### 解题思路
利用java的indexOf（int ch，int，fromIndex）
这个方法就是说从指定位置往后找返回字符在该字符串中第一次出现处的索引。
通过一个for循环，判断s中每一个字符在t中的位置，并且记录该位置t，判断s中下一个字符在t中的位置时，从
t+1这个位置开始。如果没有找到则返回-1，return false，说明t中没有s的字符串。
  遍历结束后返回true，s是t的字符串。

### 代码

```java
class Solution {
    public boolean isSubsequence(String s, String t) {
        int index = -1;
        for (char c : s.toCharArray()){
            index = t.indexOf(c, index+1);
            if (index == -1) return false;
        }
        return true;
        
    }
}
```