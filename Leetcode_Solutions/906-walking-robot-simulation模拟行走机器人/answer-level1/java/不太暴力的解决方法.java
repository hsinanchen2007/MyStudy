### 解题思路
使用Map记录路径上会存在的障碍

### 代码

```java
class Solution {
    public int robotSim(int[] commands, int[][] obstacles) {
        int x = 0;
        int y = 0;
        int result = 0;
        //0-北，1-东，2-南，3-西
        int faceDir = 0;
        Map<Integer, List<Integer>> yOnX = new HashMap<>(obstacles.length);
        Map<Integer, List<Integer>> xOnY = new HashMap<>(obstacles.length);
        for (int[] obstacle : obstacles) {
            List<Integer> yList = yOnX.get(obstacle[0]);
            if (Objects.isNull(yList)) {
                yList = new ArrayList<>();
            }
            yList.add(obstacle[1]);
            yOnX.put(obstacle[0], yList);

            List<Integer> xList = xOnY.get(obstacle[1]);
            if (Objects.isNull(xList)) {
                xList = new ArrayList<>();
            }
            xList.add(obstacle[0]);
            xOnY.put(obstacle[1], xList);
        }
        for (int command : commands) {
            if (Objects.equals(-1, command)) {
                faceDir += 1;
                if (faceDir > 3) {
                    faceDir = 0;
                }
            } else if (Objects.equals(-2, command)) {
                faceDir -= 1;
                if (faceDir < 0) {
                    faceDir = 3;
                }
            } else {
                // 面朝北方， y+++
                if (faceDir == 0) {
                    y = positiveMove(yOnX, command, y, x);
                }
                // 面朝东方， x+++
                if (faceDir == 1) {
                    x = positiveMove(xOnY, command, x, y);
                }
                // 面朝西方， y---
                if (faceDir == 2) {
                    y = negativeMove(yOnX, command, y, x);
                }
                // 面朝南方， x---
                if (faceDir == 3) {
                    x = negativeMove(xOnY, command, x, y);
                }
                result = Math.max(result, (x * x + y * y));
            }
        }
        return result;
    }

    private int positiveMove(Map<Integer, List<Integer>> map, int command, int moveAxis, int holdAxis) {
        if (Objects.isNull(map)) {
            return moveAxis + command;
        }
        List<Integer> obsList = map.get(holdAxis);
        if (Objects.isNull(obsList)) {
            return moveAxis + command;
        }
        // 排序后就能得到离当前位置最近的障碍
        obsList.sort(Comparator.naturalOrder());
        int tempMove = moveAxis + command;
        for (Integer obsInList : obsList) {
            if (tempMove >= obsInList && obsInList > moveAxis) {
                return obsInList - 1;
            }
        }
        return tempMove;
    }

    private int negativeMove(Map<Integer, List<Integer>> map, int command, int moveAxis, int holdAxis) {
        if (Objects.isNull(map)) {
            return moveAxis - command;
        }
        List<Integer> obsList = map.get(holdAxis);
        if (Objects.isNull(obsList)) {
            return moveAxis - command;
        }
        // 排序后就能得到离当前位置最近的障碍
        obsList.sort(Comparator.reverseOrder());
        int tempMove = moveAxis - command;
        for (Integer obsInList : obsList) {
            if (tempMove <= obsInList && obsInList < moveAxis) {
                return obsInList + 1;
            }
        }
        return tempMove;
    }
}
```