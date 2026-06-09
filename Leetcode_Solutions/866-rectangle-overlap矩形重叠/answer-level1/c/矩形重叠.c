### 解题思路
重合应该是一个∠在另外一个矩形中

### 代码

```c
#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)

bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){

    return MAX(rec1[0],rec2[0])<MIN(rec1[2],rec2[2])
        &&MAX(rec1[1],rec2[1])<MIN(rec1[3],rec2[3]);

}
```