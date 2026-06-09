### 解题思路
牛皮

### 代码

```java
class Solution {
    public int leastInterval(char[] tasks, int n) {
       int[] map = new int[26];
        for (char task : tasks) {
            map[task - 'A']++;
        }
        Arrays.sort(map);
        int p = map[25];
        int res = (p - 1) * (n + 1) + 1;
        for (int i = 24; i >= 0; i--) {
            if (map[i] == p) {
                res++;
            }else break;
        }
        return Math.max(res, tasks.length);
    }
}
```