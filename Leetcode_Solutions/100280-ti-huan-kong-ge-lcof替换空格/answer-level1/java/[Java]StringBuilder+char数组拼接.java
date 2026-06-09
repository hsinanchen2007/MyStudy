### 解题思路
StringBuilder+char数组，实现高效拼接

执行用时 : 0 ms, 在所有 Java 提交中击败了 100.00% 的用户
内存消耗 : 36.8 MB, 在所有 Java 提交中击败了 100.00% 的用户

### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        StringBuilder sb = new StringBuilder();
        char[] charArray = s.toCharArray(); // 避免反复调用，使用本地变量存储
        for( char c: charArray ){ // for-each底层优化为iterator迭代取值
            if( c == ' ' ) sb.append("%20"); // 读取并替换
            else sb.append(c); // 正常拼接
        }
        return sb.toString();
    }
}
```