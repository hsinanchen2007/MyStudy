
一开始是用dp做的，其实我做的过程中也有隐约感觉用图做可能会更好，但是非科班出身，图方面除了概念更本没有储备。在题解里看到大佬们说用二分图来做，找到了方向，所以就有空时断断续续自学了一天多二分图与最大匹配方面的知识。[个人学习的总结，有需要的也可以稍微看一下](https://www.uetty.com/article/2020-02-23-bipartite-graph)

对于这道题条件主要可以概括为，斜向相邻位置和左右相邻位置不能同时坐人。  
我们可以将不能同时坐人的位置连线作为边，显然偶数位置之间没有连线、奇数位置之间没有连线，所以该图是二分图。
该问题是求不冲突的座位方案，问题明显可以转化为了求二分图最大独立集点个数，独立集内没有连线，当然不会冲突，思路大概就这样。

代码如下（运行时间2ms），需要对二分图了解才好看懂

```java

class Solution {

    class Point {
        int idx;
        Point next;

        List<Point> edges = new ArrayList<>(6);

        public boolean equals(Object obj) {
            Point p = (Point) obj;
            return p.idx == idx;
        }

        public int hash() {
            return idx;
        }
    }

    Point ahead = new Point();
    Point alast = ahead;
    int totalA = 0;

    int totalB = 0;

    Point[] index = new Point[64];
    int[] matched = new int[64];

    private void addEdge(int idx1, int idx2) {
        if (index[idx2] != null) {
            index[idx1].edges.add(index[idx2]);
            index[idx2].edges.add(index[idx1]);
        }
    }

    private void match() {
        Point p = ahead;
        while ((p = p.next) != null) {
            match(p);
        }
    }

    private void match(Point p) {
        List<Point> edges = p.edges;
        int m = -1;
        for (int i = 0; i < edges.size(); i++) {
            if (matched[edges.get(i).idx] == -1) {
                m = edges.get(i).idx;
                break;
            }
        }
        if (m != -1) {
            matched[m] = p.idx;
            matched[p.idx] = m;
            return;
        }
        Set<Integer> path = new HashSet<>(totalB);
        replaceMatch(p, path);
    }

    private boolean replaceMatch(Point p, Set<Integer> path) {
        List<Point> edges = p.edges;
        for (int i = 0; i < edges.size(); i++) {
            Point q = edges.get(i);
            if (path.contains(q.idx)) {
                continue;
            }

            int midx = matched[q.idx];
            if (midx == -1) {
                matched[q.idx] = p.idx;
                matched[p.idx] = q.idx;
                return true;
            }

            path.add(q.idx);
            boolean success = replaceMatch(index[midx], path);
            if (success) {
                matched[q.idx] = p.idx;
                matched[p.idx] = q.idx;
                return true;
            } else {
                path.remove(q.idx);
            }
        }
        return false;
    }

    private void init(char[][] seats) {
        Arrays.fill(matched, -1);
        for (int i = 0; i < seats.length; i++) {
            for (int j = 0; j < seats[i].length; j++) {
                if (seats[i][j] == '.') {
                    int idx = i * 8 + j;
                    Point p = new Point();
                    p.idx = idx;
                    index[idx] = p;
                    if ((j & 1) == 0) {
                        alast.next = p;
                        alast = p;
                        totalA++;
                    } else {
                        totalB++;
                    }

                    if (i > 0) {
                        if (j > 0) {
                            addEdge(idx, idx - 9);
                        }
                        if (j < 7) {
                            addEdge(idx, idx - 7);
                        }
                    }
                    if (j > 0) {
                        addEdge(idx, idx - 1);
                    }
                }
            }
        }
    }

    public int maxStudents(char[][] seats) {
        init(seats);
        
        if (totalA == 0) {
            return totalB;
        }
        if (totalB == 0) {
            return totalA;
        }


        match();

        int count = 0;
        Point p = ahead;
        while ((p = p.next) != null) {
            if (matched[p.idx] != -1) {
                count++;
            }
        }
    
        return totalA + totalB - count;
    }
}
```