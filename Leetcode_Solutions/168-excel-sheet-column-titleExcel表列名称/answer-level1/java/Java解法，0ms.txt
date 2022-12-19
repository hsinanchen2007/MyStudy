执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :33.8 MB, 在所有 Java 提交中击败了54.03%的用户

### 解题思路
本质为26进制的转换

### 代码

```java
class Solution {
    public String convertToTitle(int n) {
        StringBuilder answer = new StringBuilder();
        int modNum;
        while (n > 0) {
            n--;
            modNum = n - (n/26) * 26;
            answer.insert(0,(char) (modNum+65));
            n /= 26;
        }
        return answer.toString();
    }
}
```