### 解题思路
此处撰写解题思路

### 代码

```java
    class Solution {
        class point {
            int length;
            int num;

        point(int length, int num) {
            this.length = length;
            this.num = num;
        }
    }

    public int[][] kClosest(int[][] points, int K) {
            int[][] result = new int[K][2];
            List<point> resultList = new ArrayList<>();

            for (int i = 0; i < points.length; i++) {
                resultList.add(new point(points[i][0] * points[i][0] + points[i][1] * points[i][1], i));
            }

            Collections.sort(resultList, new Comparator<point>() {
                @Override
                public int compare(point o1, point o2) {
                    return o1.length - o2.length;
                }
            });

            for (int i = 0; i < K; i++) {
                result[i]=points[resultList.get(i).num];
            }
            return result;
    }
}
```