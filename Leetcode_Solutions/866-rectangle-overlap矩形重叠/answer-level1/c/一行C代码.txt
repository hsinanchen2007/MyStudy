### 解题思路
重叠的充要条件是：x轴有交集 且 y轴有交集
### 代码

```c
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    return ((rec1[2] > rec2[0]) && (rec2[2] > rec1[0])) && ((rec1[3] > rec2[1]) && (rec2[3] > rec1[1]));
}
```