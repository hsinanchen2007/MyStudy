### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    private static final int[][] EMPTY_ARRAY = new int[0][0];
     public int[][] kClosest(int[][] points, int K) {
        if(points.length == 0 || K<=0){
            return EMPTY_ARRAY;
        }

        if(points.length <= K){
            return points;
        }
        // 将数组自定义比较器，使得数组有序
        Arrays.sort(points, new Comparator<int[]>() {
            public int compare(int[] o1, int[] o2) {
                return (int)(Math.pow(o1[0],2)+ Math.pow(o1[1],2)-Math.pow(o2[0],2)-Math.pow(o2[1],2));
            }
        });
        return Arrays.copyOf(points,K);

    }
}
```