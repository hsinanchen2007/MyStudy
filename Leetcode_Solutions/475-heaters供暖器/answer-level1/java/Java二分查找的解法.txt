整体思路：
（1）先找到每个房屋离加热器的最短距离（即找出离房屋最近的加热器）；
（2）在所有距离中选出最大的一个即为最小覆盖半径。记住是选一个最大的距离。

/**
     * 二分查找的思路
     * 针对每个房屋都有四中可能性
     * 1，房屋的位置刚好有一个加热器，那么加热器离房屋的距离就是0
     * 2，房屋的左边没有加热器，右边有加热器，那最小距离是：加热器位置 - 房屋的位置
     * 3，房屋的左边有加热器，右边没有，那最小距离是：房屋的位置 - 加热器的位置
     * 4，房屋的左右都有加热器，那最小距离是： Min（房屋离左侧加热器的距离，房屋离右侧加热器的距离）
     */

```java
public int findRadius(int[] houses, int[] heaters) {
        Arrays.sort(heaters);

        int[] distances = new int[houses.length];
        for (int i = 0; i < houses.length; i++) {
            int left = 0;
            int right = heaters.length - 1;
            while (left < right) {
                int mid = (left + right + 1) >>> 1;
                if (heaters[mid] > houses[i]) {
                    right = mid - 1;
                } else {
                    left = mid;
                }
            }
            if (heaters[left] == houses[i]) {
                distances[i] = 0;
            } else if (heaters[left] > houses[i] && left == 0) {
                // 如果加热器在房屋的右边且房屋的左边没有加热器了
                distances[i] = heaters[left] - houses[i];
            } else if (heaters[left] < houses[i] && left == heaters.length - 1) {
                // 如果加热器在房屋的左边，且房屋的右边没有加热器了
                distances[i] = houses[i] - heaters[left];
            } else {
                // 如果房屋两边都有加加热器
                distances[i] = Math.min((heaters[left + 1] - houses[i]), (houses[i] - heaters[left]));
            }
        }

        Arrays.sort(distances);
        return distances[distances.length - 1];
    }
```
