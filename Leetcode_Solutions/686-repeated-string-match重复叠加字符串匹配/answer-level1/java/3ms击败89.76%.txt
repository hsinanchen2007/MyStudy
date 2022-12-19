### 解题思路
模拟法：重复叠加A，最大叠加长度为B.length() + A.length() * 2,因为B的头部和尾部可能含有A的部分字符.当叠加过程中B已存在于A中则输出sb.length() / A.length()，否则当达到最大叠加长度后输出-1.(tips:使用lastIndexOf是3ms,indexOf是770ms,如果有知道原因的朋友麻烦告诉我一下！)
```java
class Solution {
    public int repeatedStringMatch(String A, String B) {
        int end = B.length() + A.length() * 2;
        StringBuilder sb = new StringBuilder(A);
        while (sb.length() < end && sb.lastIndexOf(B) == -1) {
            sb.append(A);
        }
        return sb.lastIndexOf(B) != -1 ? sb.length() / A.length() : -1;
    }
}
```