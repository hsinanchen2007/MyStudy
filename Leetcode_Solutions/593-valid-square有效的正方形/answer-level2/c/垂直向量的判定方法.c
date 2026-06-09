执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :6.7 MB, 在所有 C 提交中击败了100.00%的用户
```
bool isvertical(int x1,int y1,int x2,int y2){
    return ((x1 * x2)+(y1 * y2)==0);
}
bool validSquare(int* p1, int p1Size, int* p2, int p2Size, int* p3, int p3Size, int* p4, int p4Size){
    int x12 = *p1 - *p2;
    int x13 = *p1 - *p3;
    int x14 = *p1 - *p4;
    int x23 = *p2 - *p3;
    int x24 = *p2 - *p4;
    int x34 = *p3 - *p4;
    int y12 = *(p1 + 1) - *(p2 + 1);
    int y13 = *(p1 + 1) - *(p3 + 1);
    int y14 = *(p1 + 1) - *(p4 + 1);
    int y23 = *(p2 + 1) - *(p3 + 1);
    int y24 = *(p2 + 1) - *(p4 + 1);
    int y34 = *(p3 + 1) - *(p4 + 1);
    if((x12||y12)&&(x13||y13)&&(x14||y14)&&(x23||y23)&&(x24||y24)&&(x34||y34)){
        if((isvertical(x12,y12,x34,y34))&&(isvertical(x13,y13,x14,y14))&&(isvertical(x23,y23,x24,y24))){
            return true;
        }
        else if((isvertical(x13,y13,x24,y24))&&(isvertical(x12,y12,x14,y14))&&(isvertical(x23,y23,x34,y34))){
            return true;
        }
        else if((isvertical(x14,y14,x23,y23))&&(isvertical(x12,y12,x13,y13))&&(isvertical(x24,y24,x34,y34))){
            return true;
        }
    }
    return false;
}

```
