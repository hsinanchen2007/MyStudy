### 解题思路

直接遍历自己已经有的石头，计数记录到一个`int[] table`中，在遍历宝石列表，从计数表中获取结果并累加即可

![image.png](https://pic.leetcode-cn.com/b898f4308e3b3f4c6a60acc3152ef4be397ddc819f8eea14d5f7d873f56aee1d-image.png)


### 代码

```java
class Solution {
    public int numJewelsInStones(String J, String S) {
        int[] table = new int[128];
        for (char c : S.toCharArray()) {
            table[c] += 1;
        }
        int ret = 0;
        for (char c : J.toCharArray()) {
            ret += table[c];
        }
        return ret;
    }
}
```