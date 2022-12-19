### 执行结果
执行用时 :0 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :37.7 MB, 在所有 Java 提交中击败了100.00%的用户

### 解题思路
- 1.判断字符串不为null，并且都是相等长度。否则不需要继续判断。
- 2.在前置条件下，逐位取出char，把ascii 码 - 最小值 -128。等到相对值。
- 3.存入counter 中，s1 的走++ ，s2 的走-- 。
- 4.最后如果字符出显的次数一直。那所有的counter 都为0 。那就是true 。否则 false 。

简单的思路。仅供参考。


### 代码

```java
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        boolean br = (s1 != null && s2 != null && s1.length() == s2.length());
        if (br) {
            int[] counter = new int[256];
            for (int i = 0; i < s1.length(); i++) {
                int v1 = s1.charAt(i) - (-128);
                int v2 = s2.charAt(i) - (-128);
                counter[v1]++;
                counter[v2]--;
            }

            for (int i = 0; i < counter.length && br; i++) {
                br = counter[i] == 0;
            }

        }
        return br;
    }
}
```