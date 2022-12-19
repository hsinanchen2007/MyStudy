### 解题思路
第一次遍历找出第K大的距离。这里用到了TreeSet，同时为了避免删除距离相等的元素，重写了比较器。
第二遍直接取答案了。

### 代码

```java
class Solution {
    public int[][] kClosest(int[][] points, int K) {
        TreeSet<Integer> ts = new TreeSet(new Comparator<Integer>() { //重写一下比较器，使他可以保存相同的元素。
            @Override
            public int compare(Integer i, Integer j) {
                if (i > j) return -1;
                return 1;
            }
        });
        for (int i = 0; i < points.length; ++i) {
            int temp = points[i][0] * points[i][0] + points[i][1] * points[i][1]; //遍历每个点到原点的距离。保存最小的K个距离。
            if (ts.size() < K) {
                ts.add(temp);
            } else {
                if (ts.first() > temp) {
                    ts.pollFirst();
                    ts.add(temp);
                }
            }
        }
        int index = ts.pollFirst(); // 拿出第K大距离。
        int[][] res = new int[K][2];
        int j = 0;
        for (int i = 0; i < points.length; ++i) { //第二次遍历，距离小于第K大距离的点就是我们要的了。
            int temp = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            if (temp <= index) {
                res[j] = points[i];
                ++j;
            }
        }
        return res;
    }
}
```