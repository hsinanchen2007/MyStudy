### 解题思路
边界坐标的比较

### 代码

```c
#define x1 0
#define y1 1
#define x2 2
#define y2 3
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size)
{
    if(rec2[x1]>=rec1[x2]||rec2[y1]>=rec1[y2]||rec1[x1]>=rec2[x2]||rec1[y1]>=rec2[y2])
    return false;
    else return true;
}
```