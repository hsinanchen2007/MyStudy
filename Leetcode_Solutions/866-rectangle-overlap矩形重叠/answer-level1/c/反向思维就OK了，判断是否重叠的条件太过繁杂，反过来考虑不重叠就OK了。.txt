### 解题思路
不定义X1,Y1之类的也可以。我是因为刚开始正向考虑条件的时候为了清晰思路加的。

### 代码

```c
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size)
{


    int x1=rec1[0];int y1=rec1[1];int x2=rec1[2];int y2=rec1[3];
    int X1=rec2[0];int Y1=rec2[1];int X2=rec2[2];int Y2=rec2[3];

    if((X2<=x1)||(X1>=x2)||(Y2<=y1)||(Y1>=y2))
        return false;

    return true;

}
```