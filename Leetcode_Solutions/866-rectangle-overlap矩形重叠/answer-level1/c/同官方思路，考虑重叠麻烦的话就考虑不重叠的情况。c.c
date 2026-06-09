```
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    int x11=rec1[0],y11=rec1[1],x12=rec1[2],y12=rec1[3];
    int x21=rec2[0],y21=rec2[1],x22=rec2[2],y22=rec2[3];
    if(x22<=x11 || y22<=y11 || x21>=x12 || y21>=y12)
        return false;
    return true;
}
```
