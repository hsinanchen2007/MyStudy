### 思路
各位可以把图画出来就一目了然了。也就是两个矩形的横坐标之间必须有重叠、纵坐标之间也必须有重叠。

```java
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        return rec2[0] < rec1[2] && rec2[2] > rec1[0] && rec2[1] < rec1[3] && rec2[3] > rec1[1];
    }
```