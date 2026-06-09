假定一个矩形的表示是  (xl, yl, xr,yr)
表示从左下角下标 (xl,yl)到右上角下标 (xr,yr)的矩形

 下面的解法使用两个堆来存放所有的矩形
 1. 第一个堆 allHeap 存放所有的矩形， 按(xl,yl)排序
 2. 第二个堆 matchHead 存放当前所有需要匹配的矩形, 按(xr,yl)排序
 
**算法的基本思想：从左到右依次补齐每个部分的矩形，直到遍历完所有的矩形.堆 matchHead存放了当前需要匹配的最左边的那个矩形**


算法初始化时首先按照相同最小xl，按yl递增的方式构造matchHead的初始值，并检查这些矩形是否依次叠加
 
每次循环时，从allHeap中取出能够与当前需要匹配的矩形唯一矩形，然后更新matchHead

循环结束时，如果matchHead中还有需要匹配的矩形，则检查它们的右侧的边是否依次叠加

```java
 class Solution {
        static Comparator<int[]> comp = new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                int d = o1[0] - o2[0];
                return d == 0 ? o1[1] - o2[1] : d;
            }
        };
        static Comparator<int[]> compByRight = new Comparator<int[]>() {
            @Override
            public int compare(int[] o1, int[] o2) {
                int d = o1[2] - o2[2];
                return d == 0 ? o1[1] - o2[1] : d;
            }
        };
        public boolean isRectangleCover(int[][] rectangles) {
            if (rectangles.length == 0) {
                return true;
            }
            // 构造两个堆，快速取出最小值
            PriorityQueue<int[]> allHeap = new PriorityQueue<>(rectangles.length, comp);
            PriorityQueue<int[]> matchHead = new PriorityQueue<>(rectangles.length, compByRight);

            for (int i = 0; i < rectangles.length; i++) {
                allHeap.add(rectangles[i]);
            }

            // 检查和初始化最左下角的所有矩形
            int[] last = allHeap.poll();
            matchHead.add(last);
            while (!allHeap.isEmpty()) {
                int[] head = allHeap.peek();
                if (head[0] != last[0]) {
                    break;
                }
                allHeap.poll();
                if (head[1] != last[3]) {
                    return false;
                }
                matchHead.add(head);
                last = head;
            }

            // 每次循环取出当前需要匹配的那个矩形，与allMap中的唯一候选矩形进行匹配并更新matchHead
            int[] head = matchHead.poll();
            while (!allHeap.isEmpty()) {
                int[] cur = allHeap.poll();
                int lastyl = cur[1];
                while (true) {
                    if (cur[0] == head[2] && lastyl == head[1]) {
                        if (cur[3] > head[3]) {
                            lastyl = head[3];
                            if (matchHead.isEmpty()) {
                                return false;
                            }
                            head = matchHead.poll();
                            continue;
                        }
                        matchHead.add(cur);
                        if (cur[3] == head[3]) {
                            head = matchHead.poll();
                        } else {
                            head[1] = cur[3];
                        }
                        break;
                    } else {
                        return false;
                    }
                }
            }
            // 循环结束后, 检查matchHead中的所有矩形是否叠加
            while (!matchHead.isEmpty()) {
                int[] e = matchHead.poll();
                if (head[2] != e[2] || head[3] != e[1]) {
                    return false;
                }
                head = e;
            }
            return true;
        }
    }
```