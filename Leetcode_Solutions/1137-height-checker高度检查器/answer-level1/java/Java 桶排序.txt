### 解题思路
先按照桶排序走一遍，然后用桶排序后的结果逐个和原数组比较

### 代码

```java
class Solution {
    public int heightChecker(int[] heights) {
        int[] hs = new int[101];
        for (int n : heights) {
            hs[n] ++;
        }
        int cnt = 0;
        for (int i = 0, j = 0; i < hs.length; i ++) {
            while (hs[i] > 0) {
                if (heights[j] != i) {
                    cnt ++;
                }
                j ++;
                hs[i]--;
            }
        }
        return cnt;
    }
}
```