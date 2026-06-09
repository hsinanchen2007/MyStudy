### 解题思路
此题为卡特兰数的应用，以后要研究一下的。
然后还有一种做法是用动态规划做的。可以看下答案。

### 代码

```java
class Solution {
    //此题为卡特兰数的应用
    public int numTrees(int n) {
        long cnt = 1;
        for (int i = 0; i < n; ++i) {
            cnt = cnt * 2 * (2 * i + 1) / (i + 2);
        }
        return (int) cnt;
    }
}
```