### 解题思路
该方案是官方的最后一种解题思路，做该体检
用char其实是数字的ascii编码，很好的用int[]替换了HashMap
#### 比较拗口的地方
比较难以理解的是这段代码：ascii[s.charAt(j)] = j + 1;
其实是官方用该段代码简写了以下逻辑：
假设：ascii[s.charAt(j)] = j;   （不是等于原有的j + 1）
1. 当i = j时，res = j - i + 1 = 1      （比如刚开始i、j都为0的时候）
2. 当i < j时，res = j - i;
所以为了代码的简洁，统一：res = Math.max(res, j - i + 1);
当i < j时，把i也+1处理，统一定义：i为滑动窗口的开头，而不是滑动窗口的前一个下标

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        int n = s.length();
        int[] ascii = new int[128];
        int res = 0;
        for (int i = 0, j = 0; j < n; j++) {
            i = Math.max(i, ascii[s.charAt(j)]);
            res = Math.max(res, j - i + 1);
            ascii[s.charAt(j)] = j + 1;
        }
        return res;
    }

}
```