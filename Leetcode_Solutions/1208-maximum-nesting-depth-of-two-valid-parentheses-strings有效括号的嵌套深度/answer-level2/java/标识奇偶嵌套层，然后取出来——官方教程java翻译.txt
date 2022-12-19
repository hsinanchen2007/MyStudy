### 解题思路
标识奇偶嵌套层，然后取出来——官方教程java翻译

### 代码

```java
class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int[] res = new int[seq.length()];
        for (int i = 0,index = 0; i < res.length; i++)
            if (seq.charAt(i) == ')') res[i] = --index % 2;
            else res[i] = index++ % 2;
        return res;
    }
}
```