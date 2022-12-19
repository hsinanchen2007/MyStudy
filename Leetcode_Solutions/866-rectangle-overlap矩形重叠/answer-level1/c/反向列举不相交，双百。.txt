### 解题思路
反向列举不相交，双百。路

### 代码

```c
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    if(rec2[3]<=rec1[1]) return false;//左
    if(rec2[0]>=rec1[2]) return false; //上
    if(rec2[1]>=rec1[3]) return false;//右
    if(rec2[2]<=rec1[0]) return false;//下
    return true;
}
```