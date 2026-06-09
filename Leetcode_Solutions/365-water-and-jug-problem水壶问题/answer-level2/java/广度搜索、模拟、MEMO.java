这题关键是拆解三个动作对应的容器里水的状态.

初始状态为(0,0) 目标是达到某一个状态(x,y)满足x == z || y == z || x+y == z

状态的变化路径分为四种类型
1. 容器为0，则将某个容器装满
2. 容器非空，则将某个容器倒出
3. 左容器非空，左往右容器倒
4. 右容器非空，右容器往左倒

这里其实有个状态没提到，容器非空的时候，将其装满。
由于从题可以分析得到，不可能存在某一个状态，使得两个容器都非空且都不满。
因此，如果容器非空，将其装满，意味着两个容器都满了或者一个满，另一个为空（这些状态显然是已经访问过的）。

整个状态搜索过程中，用Set来记录访问过的状态，避免无限循环.



```
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        Queue<Pair> q = new LinkedList<>();
        Set<Pair> visited = new HashSet<>();
        addStatus(0,0,q,visited);
        while (!q.isEmpty()) {
            Pair pair = q.poll();
            if (pair.x == z || pair.y == z || pair.x+pair.y == z) {
                return true;
            }

            // 倒满的尝试
            if (pair.x == 0) {
                addStatus(x, pair.y, q, visited);
            }
            if (pair.y == 0) {
                addStatus(pair.x, y, q, visited);
            }

            // 倒出的尝试
            if (pair.x > 0) {
                addStatus(0, y, q, visited);
            }
            if (pair.y > 0) {
                addStatus(pair.x, 0, q, visited);
            }

            // 左倒给右的尝试
            if (pair.x > 0) {
                int size = Math.min(pair.x, y-pair.y);
                addStatus(pair.x - size, pair.y + size, q, visited);
            }

            // 右倒给左的尝试
            if (pair.y > 0) {
                int size = Math.min(pair.y, x-pair.x);
                addStatus(pair.x + size, pair.y - size, q, visited);
            }
        }
        return false;
    }

    private void addStatus(int x, int y, Queue<Pair> q, Set<Pair> visited) {
        Pair p = new Pair(x,y);
        if (!visited.contains(p)) {
            q.add(p);
            visited.add(p);
        }
    }

    
    class Pair {
        int x;
        int y;

        Pair(int x, int y) {
            this.x = x;
            this.y = y;
        }

        @Override
        public boolean equals(Object obj) {
            if (obj instanceof Pair) {
                Pair pair = (Pair) obj;
                return this.x == pair.x && this.y == pair.y;
            } else {
                return super.equals(obj);
            }
        }

        @Override
        public int hashCode() {
            int result = 17;
            result = result * 31 + x;
            result = result * 31 + y;
            return result;
        }
    }
}
```
