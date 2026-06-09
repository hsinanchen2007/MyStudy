### 解题思路

这里的解题思路参考了 官方题解中的第二种思路

至多有 h 篇论文分别被引用了至少 h 次。
* 思路:
* 对n篇文章被引用的次数进行统计
* 根据被引用的次数 放入 0 1 2..... n  一共 n+1 个桶 a 中
* 如果 a[?>x] >= x 则 结果为 x


### 代码

```java
class Solution {

    public static int hIndex(int[] citations) {
        int n = citations.length;
        int[] papers = new int[n + 1];
        // 计数
        for (int c : citations) {
            papers[Math.min(n, c)]++;
        }
        int cur = 0;
        for (int i = n; i > 0; i--) {
            if (papers[i] + cur >= i) {
                return i;
            }
            cur += papers[i];
        }
        return 0;
    }
}
```