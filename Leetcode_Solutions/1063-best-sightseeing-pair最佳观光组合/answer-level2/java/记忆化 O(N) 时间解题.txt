### 解题思路
如果一个位置作为起点，它的贡献则为 A[i] + i
如果一个位置作为终点，它的贡献为 A[i] - i
我们可以按照终点来进行计算，如果选取当前 i 作为终点，那么我们可以知道前面 `0` ~ `i-1` 中效益最高的起点是多少
最后选择一个最大 i 即可

### 代码

```java
class Solution {
    public int maxScoreSightseeingPair(int[] A) {
        int len = A.length-1;
        int[] start = new int[len];
        int[] end = new int[len];
        for(int i = 0; i < len; i++){
            start[i] = A[i] + i;
        }
        for(int i = 1; i < len+1; i++){
            end[i-1] = A[i] - i;
        }
        int maxStart = start[0];
        int res = start[0] + end[0];
        for(int i = 0; i < len; i++){
            maxStart = Math.max(maxStart, start[i]);
            res = Math.max(res, end[i] + maxStart);
        }
        return res;
    }
}
```