
# 广度优先搜索
我们要用一种方式来表示当前两个水壶的状态，这里可以自己选择，比如利用字符串，把两个水壶当前的水量用下划线拼接起来。我这选择的构造一个新的类 `Pair`
```java
private class Pair {
    int x;
    int y;

    Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public int sum() {
        return this.x + this.y;
    }
    @Override
    public int hashCode() {
        return x * 10 + y;
    }

    @Override
    public boolean equals(Object o) {
        if (o instanceof Pair) {
            Pair tmp = (Pair) o;
            if (tmp.x == this.x && tmp.y == this.y) {
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }
}
```
至于这里为什么需要 `Override` hashCode 和 equals 这两个方法，是为了后面使用 HashSet 来判断状态是否已经出现过了。代码如下：
```java
 private void addPair(Pair pair, Queue<Pair> q, HashSet<Pair> s) {
 	if (s.add(pair)) {
        q.offer(pair);
    }
}
```
### 如何改变水壶的状态？
有几个要点：
##### 1 每一步只能对一个水壶针对一个操作
##### 2 如果一个水壶是空的，那么下一步只能是灌满
##### 3 如果一个水壶是非空的，那么可选项就多了，有三种情况
1. **清空**：清空当前这个非空的水壶
2. **灌满**：把这个水壶灌满，注意：这里你完全不用管这水壶到底是不是满的，因为我们可以用的 HashSet 来进行去重判断
3. **把水倒入另一个水壶中**：这里需要判断 **另一个水壶里还剩下多少的空间** 。
	- 如果另一个水壶里剩下的空间 **大于** 当前 的水壶的水量，那么就全倒入另一个水壶中。
	- 如果另一个水壶里剩下的空间 **小于** 当前 的水壶的水量，那么就倒如另一个水壶中，直至另一个满为止。然后当前的水壶依然剩下一部分水。

# 广度优先搜索的代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if (z == 0) {
            return true;
        }
        if (x + y < z) {
            return false;
        }
        int small = x;
        int big = y;
        if (x > y) {
            small = y;
            big = x;
        }
        if (small == 0) {
            return big == z;
        }

        while (big % small != 0) {
            int tempSmall = big % small;
            big = small;
            small = tempSmall;
        }
        return z % small == 0;
    }

    private void addPair(Pair pair, Queue<Pair> q, HashSet<Pair> s) {
        if (s.add(pair)) {
            q.offer(pair);
        }
    }

    private class Pair {
        int x;
        int y;

        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public int sum() {
            return this.x + this.y;
        }
        @Override
        public int hashCode() {
            return x * 10 + y;
        }

        @Override
        public boolean equals(Object o) {
            if (o instanceof Pair) {
                Pair tmp = (Pair) o;
                if (tmp.x == this.x && tmp.y == this.y) {
                    return true;
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
    }
}
```