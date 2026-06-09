### 解题思路
JAVA 贪心算法 每轮时间为n+1, 先执行任务数量最多的任务

### 代码

```java
class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] array = new int[26];
        for (char ch : tasks) {
            array[ch - 'A']++;
        }
        Arrays.sort(array);
        int time = 0;
        while (array[25] > 0) {
            for (int i = 0; i < n + 1; i++) {
                if(array[25] == 0) {
                    break;
                }
                if (25 - i >= 0 && array[25 - i] > 0) {
                    array[25 - i]--;
                }
                time++;
            }
            Arrays.sort(array);
        }
        return time;
    }
}
```