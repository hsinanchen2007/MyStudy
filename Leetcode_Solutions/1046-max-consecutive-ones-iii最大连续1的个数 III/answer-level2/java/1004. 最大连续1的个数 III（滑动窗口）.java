### 解题思路
424. 替换后的最长重复字符一样的套路,如果没做过这题，这个可能不太好想（另外，最大连续1的个数II这个题就是K = 1的情况，会员题）

### 代码

```java
class Solution {
    public int longestOnes(int[] A, int K) {
        int ans = 0;//结果
        int zero = 0;//滑动窗口中0的个数
        int start = 0;//滑动窗口左边界
        int end = 0;//滑动窗口右边界
        int len = A.length;//数组长度
        while (end < len) {
            if (A[end] == 0) {
                zero++;
                if (zero <= K) {
                    ans = Math.max(end - start + 1, ans);
                } else {
                    while (zero > K) {
                        if (A[start] == 0) {
                            zero--;
                        }
                        start++;
                    }
                }
            } else {
                ans = Math.max(end - start + 1, ans);
            }
            end++;
        }
        //最后出循环时特判一下
        if (start < end) {
            ans = Math.max(end - start, ans);
        }
        return ans;
    }
}
```