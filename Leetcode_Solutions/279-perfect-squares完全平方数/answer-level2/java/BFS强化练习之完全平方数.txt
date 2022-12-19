![屏幕快照 2019-08-27 下午11.42.06.png](https://pic.leetcode-cn.com/4a86c642f7615de24ba7b60adc0a14f7a7045dc83505f6a189d9aa89ebd97085-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-08-27%20%E4%B8%8B%E5%8D%8811.42.06.png)

如上图所示, 以12为例. 
BFS是宽搜索, 以0为起点, 按层遍历, 第一层默认为0. 
第二层为 `0 + i^2 <= n, i in [1, sqrt(n)]` 的完全平方数之和next, 如果next没有在队列中出现过则添加至队列尾部. 图上添加了`1, 4, 9`.
第二层为 `第二层每个值(共三个,分别为1, 4, 9) + i^2, i in [1, sqrt(n)]` 的完全平方数之和next, 如果next没有在队列中出现过, 则添加至队列尾部. 图上添加了`2,5,10,8`.
第三层为 `第三层每个值(共四个, 分别为2,5,10,8) + i^2, i in [1, sqrt(n)]` 的完全平方数之和next, 如果next没有在队列中出现过, 则添加至队列尾部. 图上添加了`3,6,11`,且在这一层next = 8 + 2^2 = 12, 直接返回dist. 

java代码

```
    public int numSquares(int n) {
        Queue<Integer> que = new LinkedList<>();
        Set<Integer> visited = new HashSet<>();
        // 与0点的距离
        int dist = 0;
        que.add(0);
        visited.add(0);
        while (!que.isEmpty()) {
            dist++;
            int size = que.size();
            for (int j = 0; j < size; j++) {
                int cur = que.remove();
                for (int i = 1; i * i + cur <= n; i++) {
                    int squre = i * i;
                    int next = squre + cur;
                    if (next == n) return dist;
                    if (!visited.contains(next) && next < n) {
                        que.add(next);
                        visited.add(next);
                    }
                }
            }
        }
        return dist;
    }
```

