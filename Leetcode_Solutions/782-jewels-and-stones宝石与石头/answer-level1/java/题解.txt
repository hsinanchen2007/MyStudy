### 解题思路
用的暴力解法，但是超过了99%，可能是indexOf的方法比较快吧，用HashMap也可以写，但我比较懒。。。

### 代码

```java
class Solution {
    public int numJewelsInStones(String J, String S) {
        int sum = 0;
        for (int i = 0; i < S.length(); i++) {
            if (J.indexOf(S.charAt(i)) != -1) sum++;
        }
        return sum;
    }
}
```