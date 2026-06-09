# 代码
```java [-统计每年的人数变化(2 ms)]
class Solution {
    public int maxAliveYear(int[] birth, int[] death) {
        int[] changes = new int[102];
        int len = birth.length, res = 1900, max_alive = 0, cur_alive = 0;
        for (int i = 0; i < len; ++i) {
            ++changes[birth[i] - 1900];
            --changes[death[i] - 1899];
        }
        for (int i = 1; i < 101; ++i) {
            cur_alive += changes[i];
            if (cur_alive > max_alive) {
                max_alive = cur_alive;
                res = 1900 + i;
            }
        }
        return res;
    }
}
```
```java [-最小堆(96 ms)]
class Solution {
    public int maxAliveYear(int[] birth, int[] death) {
        int len = birth.length;
        int[][] people = new int[len][2];
        for (int i = 0; i < len; ++i)
            people[i] = new int[]{birth[i], death[i]};
        Arrays.sort(people, Comparator.comparingInt(person -> person[0]));
        PriorityQueue<int[]> pQueue = new PriorityQueue<>(len, Comparator.comparingInt(person -> person[1]));
        int res = people[0][0], max_lives = 0;
        for (int[] person : people) {
            while (!pQueue.isEmpty() && pQueue.peek()[1] < person[0])
                pQueue.poll();
            if (max_lives < pQueue.size()) {
                max_lives = pQueue.size();
                res = person[0];
            }
            pQueue.offer(person);
        }
        return res;
    }
}
```
# 相关题目
[1094. 拼车](https://leetcode-cn.com/problems/car-pooling/)