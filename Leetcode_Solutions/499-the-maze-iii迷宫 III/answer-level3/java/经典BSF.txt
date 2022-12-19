

**  移动路径：**
    不是直接一步步移动，如果上次有移动方向，必须按照移动方向移动
```java []

                if (moveIndex >= 0) {
                    nextX = x + moveArray[moveIndex][0];
                    nextY = y + moveArray[moveIndex][1];
                }
                if (isVaild(nextX, nextY)) {
                    // 没有遇到墙
                    add(nextX, nextY, moveIndex, new StringBuffer(moveTrace), queue);
                } else {
                    // 遇到墙
                    for (int k = 0; k < 4; k++) {
                        add(x + moveArray[k][0], y + moveArray[k][1], k,
                            new StringBuffer(moveTrace).append(moveDirs.charAt(k)), queue);
                    }
                }
```

**  访问点记录：**
```java []

                private boolean[][][] visited; 点和移动方向
```
**  移动顺序选择**

    按照字典顺序增加到队列，这样找到的点就是路径最小的点
```java []
    private String moveDirs = "dlru";
    private int[][] moveArray = new int[][] {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
```