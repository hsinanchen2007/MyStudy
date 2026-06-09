### 解题思路
此处撰写解题思路
i & (i - 1)可以去掉最后一位的1，最后加一
dp存之前算过的 i & (i - 1) 之前算过
执行用时 :
2 ms
, 在所有 Java 提交中击败了
80.94%
的用户
内存消耗 :
43.6 MB
, 在所有 Java 提交中击败了
5.15%
的用户
### 代码

```java
class Solution {
    public int[] countBits(int num) {
        int[] res = new int[num + 1];
        for (int i = 1; i < num + 1; i++){
            res[i] = res[i & (i - 1)] + 1;
        }
        return res;
    }
}
```