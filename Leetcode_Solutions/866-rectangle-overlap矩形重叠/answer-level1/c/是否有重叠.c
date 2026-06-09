```
int intMax(int a, int b) {
    return a >= b ? a : b;
}
int intMin(int a, int b) {
    return a <= b ? a : b;
}
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    /*不是矩形*/
    if (rec1[0] == rec1[2] || rec1[1] == rec1[3] || rec2[0] == rec2[2] || rec2[1] == rec2[3]) {
        return false;
    }
    if (intMax(rec1[0], rec1[2]) <= intMin(rec2[0], rec2[2]) || intMin(rec1[0], rec1[2]) >= intMax(rec2[0], rec2[2])
    || intMax(rec1[1], rec1[3]) <= intMin(rec2[1], rec2[3]) || intMin(rec1[1], rec1[3]) >= intMax(rec2[1], rec2[3])) {
        return false;
    }
    return true;;
}
```
