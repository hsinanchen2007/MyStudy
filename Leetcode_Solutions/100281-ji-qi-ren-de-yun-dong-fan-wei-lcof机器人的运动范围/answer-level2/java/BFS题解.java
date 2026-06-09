### 解题思路
首先定义一个`deque`来存放符合的格子坐标，以及一个`map`来记录符合的坐标，为的是在搜索的过程中，避免重复搜索相同的格子，导致算法无限循环。分别初始化这两个集合容器，因为从坐标原点（0,0）出发，所以我们只需要往向上以及向右进行搜索即可，然后求数位之和是否满足不大于K的条件。如果满足，则坐标点符合，放入集合容器内，如果不满足则抛弃。

### 代码

```java
class Solution {
    public int movingCount(int m, int n, int k) {
        Deque<int[]> deque = new LinkedList<>();
        int[][] indexArray = new int[][] {{0,1}, {1,0}};
        deque.add(new int[]{0,0});
        Map<String, Integer> map = new HashMap<>();
        map.put("0,0", 1);
        int total = 1;
        while (!deque.isEmpty()) {
            int currentSize = deque.size();
            for (int i=0; i<currentSize; ++i) {
                int[] arr = deque.poll();
                for (int j=0; j<4; ++j) {
                    int positionX = arr[0] + indexArray[j][0];
                    int positionY = arr[1] + indexArray[j][1];
                    if (positionX >= 0 && positionX < m && positionY >= 0 && positionY < n) {
                        int positionXCopy = positionX;
                        int positionYCopy = positionY;
                        int sum = 0;
                        while (positionXCopy / 10 != 0) {
                            sum = sum + positionXCopy % 10;
                            positionXCopy = positionXCopy / 10;
                        }
                        sum += positionXCopy;

                        while (positionYCopy / 10 != 0) {
                            sum = sum + positionYCopy % 10;
                            positionYCopy = positionYCopy / 10;
                        }
                        sum += positionYCopy;

                        if (sum <= k) {
                            if (map.get(positionX + "," + positionY) == null) {
                                total++;
                                deque.add(new int[]{positionX, positionY});
                                map.put(positionX + "," + positionY, 1);
                            }
                            
                        }
                    }
                }
            }
        }

        return total;
    }
}
```