### 解题思路
C一行代码完成，时间空间均100%
：）
逆向思考，如果不重叠，第二个矩形就在第一个周围的四个方向上。
### 代码

```c
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
        if (rec1[2]<=rec2[0] || rec2[2]<=rec1[0] || rec1[3]<=rec2[1] || rec2[3]<=rec1[1]) return false;
        else return true;
}
```