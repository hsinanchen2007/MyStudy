**思路**
总的来说，就是求使用最少的区间可以覆盖[0,n]。大致思路如下：
1. 设from=0，即从0开始遍历，每次遍历n+1个区间，选择区间起始节点小于等于from（即要包含from），且终止节点最大的区间；若没找到，则说明给定的区间出现了空隙，无法完整覆盖。否则，更新from为当前找到的符合包含from的区间的终止节点最大的值。
2. 不断执行步骤1，直到from==n为止。

show the code
```java
class Interval {
        int s;
        int e;
        Interval(int s, int e) {
            this.s = s;
            this.e = e;
        }
    }

    public int minTaps(int n, int[] ranges) {
        Interval[] intervals = new Interval[n+1];
        for (int i = 0; i < n + 1; i++) {
            intervals[i] = new Interval(i - ranges[i], i + ranges[i]);
        }

        int from = 0;
        boolean[] visited = new boolean[n+1];
        int ans = 0;
        while (from < n) {
            int maxEnd = 0;
            int targetIndex = -1;
            for (int i = 0; i < n + 1; i++) {
                if (!visited[i] && intervals[i].s <= from && intervals[i].e > maxEnd) {
                    maxEnd = intervals[i].e;
                    targetIndex = i;
                }
            }

            if (targetIndex == -1) {
                return -1;
            }

            from = maxEnd;
            visited[targetIndex] = true;
            ans++;
        }

        return ans;
    }
```