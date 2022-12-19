# 视频链接：[how not to die hard with math](https://www.youtube.com/watch?v=0Oef3MHYEC0)

x = 5, y = 3, z = 4
![image.png](https://pic.leetcode-cn.com/57307bf7961abe0394b896606df1d43b09652f730e7ad19c3de709c0ece8e713-image.png)

x = 15, y = 6, z = 5
![image.png](https://pic.leetcode-cn.com/e63a188161d560e4d74989c8f38291d643d776ec17666f6a8a37850a50b2ed49-image.png)

# GCD方法
```java
public boolean canMeasureWater(int x, int y, int z) {
    if (z == 0) return true;
    if (x + y < z) return false;

    int big = Math.max(x, y);
    int small = x + y - big;

    if (small == 0) return big == z;


    while (big % small != 0) {
        int temp = small;
        small = big % small;
        big = temp;
    }
    return z % small == 0;
}
```

# 极简BFS
来自：https://leetcode.com/problems/water-and-jug-problem/discuss/83716/Java-Programmatic-Solution-BFS-without-GCD
```java
public boolean canMeasureWater_BFS(int x, int y, int z) {
    if (z < 0 || z > x + y) {
        return false;
    }
    Set<Integer> set = new HashSet<>();
    Queue<Integer> q = new LinkedList<>();
    q.offer(0);
    while (!q.isEmpty()) {
        int n = q.poll();
        if (n + x <= x + y && set.add(n + x)) {
            q.offer(n + x);
        }
        if (n + y <= x + y && set.add(n + y)) {
            q.offer(n + y);
        }
        if (n - x >= 0 && set.add(n - x)) {
            q.offer(n - x);
        }
        if (n - y >= 0 && set.add(n - y)) {
            q.offer(n - y);
        }
        if (set.contains(z)) {
            return true;
        }
    }
    return false;
}
```


