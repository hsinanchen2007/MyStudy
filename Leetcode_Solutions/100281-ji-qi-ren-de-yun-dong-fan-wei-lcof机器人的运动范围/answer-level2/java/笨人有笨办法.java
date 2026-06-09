### 解题思路
模拟机器人运动，从`(0, 0)`开始，递归上下左右相邻格子，记录走过的格子坐标`set`和总数`res`：
- 如果越界，直接`return`
- 如果已经走过，`return`；否则加入`set`
- 如果行坐标和列坐标的数位之和大于`k`，`return`；否则格子数`res + 1`

### 代码

```java
class Solution {
    int m;
    int n;
    int k;
    Set<Integer> set;
    int res;

    public int movingCount(int m, int n, int k) {
        this.m = m;
        this.n = n;
        this.k = k;
        set = new HashSet<>();
        this.res = 0;
        move(0, 0);
        return res;
    }

    public void move(int x, int y) {
        if(x<0 || x>=m || y<0 || y>=n) {
            return;
        }
        int spot = x * n + y;
        if(set.contains(spot)) {
            return;
        } else {
            set.add(spot);
        }
        if(count(x, y) <= k) {
            res += 1;
        } else {
            return;
        }
        move(x+1, y);
        move(x, y+1);
        move(x-1, y);
        move(x, y-1);
    }

    public int count(int x, int y) {
        int sum = 0;
        while(x > 0) {
            sum += x % 10;
            x /= 10;
        }
        while(y > 0) {
            sum += y % 10;
            y /= 10;
        }
        return sum;
    }
}
```