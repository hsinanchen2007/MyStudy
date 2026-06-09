### 解题思路
题目不难画个图，把四种情况都画出来，然后表上把两个矩阵坐标分表代表什么写上，然后一种情况一种情况写上就行，别忘了边界
### 代码

```c
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size)
{
    if(rec2[0] >= rec1[2] || rec2[2] <= rec1[0] || rec2[1] >= rec1[3] || rec2[3] <= rec1[1])
    return false;
    else
    return true;
}
```