### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int robotSim(int[] commands, int[][] obstacles) {
        int rowPosition = 0;
        int colPosition = 0;
        int maxDistance = 0;

        int step = 0;
        int[][] vectors = new int[][]{
                {1, 0},
                {0, -1},
                {-1, 0},
                {0, 1}};

        Set<String> obstacleSet = new HashSet<>();
        for (int[] obstacle : obstacles) {
            obstacleSet.add(obstacle[1] + ":" + obstacle[0]);
        }

        for (int command : commands) {
            if (command < 0) {
                step = command == -2 ? (step + 1) % 4 : step - 1;
                step = step < 0 ? step + 4 : step;
                continue;
            }

            int rowStep = vectors[step][0];
            int colStep = vectors[step][1];

            for (int i = 1; i <= command; i++) {
                int nextRowP = rowPosition + rowStep;
                int nextColP = colPosition + colStep;
                if (obstacleSet.contains(nextRowP + ":" + nextColP)) {
                    break;
                }

                rowPosition = nextRowP;
                colPosition = nextColP;
                
                maxDistance = Math.max(
                        maxDistance, 
                        (rowPosition*rowPosition) + (colPosition*colPosition));
            }
        }

        return maxDistance;
    }
}
```