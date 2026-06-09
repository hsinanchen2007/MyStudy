```
class Solution {
    public int scheduleCourse(int[][] courses) {
        int len = courses.length;
        Arrays.sort(courses, (a, b) -> {return a[1] - b[1];});
        Queue<Integer> que = new PriorityQueue<>((a, b)->{return -a.compareTo(b);});
        int now = 0;
        int ans = 0;
        for (int[] it : courses) {
            if (now + it[0] > it[1]) {
                if (que.size() == 0) continue;
                int tmp = que.peek();
                if (now - tmp + it[0] <= it[1] && tmp > it[0]) {
                    now = now - tmp + it[0];
                    que.poll();
                    que.add(it[0]);
                }
            }
            else {
                now += it[0];
                ++ans;
                que.add(it[0]);
            }
        }
        return ans;
    }
}
```
