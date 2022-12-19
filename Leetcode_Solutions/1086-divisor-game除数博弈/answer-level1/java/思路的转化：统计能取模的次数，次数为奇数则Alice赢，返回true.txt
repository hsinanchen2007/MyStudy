### 解题思路
- 转化思路：统计能取模的次数，次数为奇数则Alice赢，返回true
- 最佳状态的理解是什么：我的理解是最小对N取模为0的数
### 代码

```java
class Solution {
    public boolean divisorGame(int N) {
        int count = 0;
        int temp = 0;
        while (N > 1) {
            for (int i = 1; i < N; i++) {
                if (N % i == 0) {
                    temp = i;
                    count++;
                    break;
                }

            }
            N -= temp;
        }
        return count % 2 == 1;
    }
}
```