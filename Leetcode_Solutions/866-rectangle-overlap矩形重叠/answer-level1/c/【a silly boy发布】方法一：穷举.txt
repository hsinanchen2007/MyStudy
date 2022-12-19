![image.png](https://pic.leetcode-cn.com/d22af7bd183cea11fb99aec54fbb9dfdd3bb9043301c79dc5e706cad1f94532b-image.png)

```
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    if ((rec1 == NULL) || (rec1Size == 0) || (rec2 == NULL) || (rec2Size == 0)) {
        return false;
    }

    //矩形--A
    int x1 = rec1[0];
    int y1 = rec1[1];
    int x2 = rec1[2];
    int y2 = rec1[3];

    //矩形--B
    int u1 = rec2[0];
    int v1 = rec2[1];
    int u2 = rec2[2];
    int v2 = rec2[3];

    //没相交
    if (((x1 > u1) && (x1 < u2)) && ((y1 > v1) && (y1 < v2))) {
        return true;
    }

    if (((x1 > u1) && (x1 < u2)) && ((y2 > v1) && (y2 < v2))) {
        return true;
    }

    if (((x2 > u1) && (x2 < u2)) && ((y2 > v1) && (y2 < v2))) {
        return true;
    }

    if (((x2 > u1) && (x2 < u2)) && ((y1 > v1) && (y1 < v2))) {
        return true;
    }

    //有相交
    if ((x1 <= u1) && (x2 >= u2) && (y1 > v1) && (y1 < v2)) {
        return true;
    }
    if ((x1 <= u1) && (x2 >= u2) && (y2 > v1) && (y2 < v2)) {
        return true;
    }

    if ((y1 <= v1) && (y2 >= v2) && (x1 > u1) && (x1 < u2)) {
        return true;
    }
    if ((y1 <= v1) && (y2 >= v2) && (x2 > u1) && (x2 < u2)) {
        return true;
    }

    if (((x1 > u1) && (x1 < u2) && (y1 > v1) && (y1 < v2)) 
        && ((x2 > u1) && (x2 < u2) && (y2 > v1) && (y2 < v2))) {
        return true;
    }

    if (((u1 > x1) && (u1 < x2) && (v1 > y1) && (v1 < y2)) 
        && ((u2 > x1) && (u2 < x2) && (v2 > y1) && (v2 < y2))) {
        return true;
    }


    return false;
}
```
