执行结果：通过
显示详情
执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 :5.2 MB, 在所有 C 提交中击败了100.00%的用户

```
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    if (rec1 == NULL || rec2 == NULL || rec1Size != 4 || rec2Size != 4) return false;
    
    int x11 = rec1[0];
    int y11 = rec1[1];
    int x12 = rec1[2];
    int y12 = rec1[3];
    
    int x21 = rec2[0];
    int y21 = rec2[1];
    int x22 = rec2[2];
    int y22 = rec2[3];
    
    //存在一个矩形的节点在另一个矩形的内部
    if ((x21 > x11 && x21 < x12) && ((y21 > y11 && y21 < y12) || (y22 > y11 && y22 < y12))) return true;
    if ((x22 > x11 && x22 < x12) && ((y21 > y11 && y21 < y12) || (y22 > y11 && y22 < y12))) return true;
    
    if ((x11 > x21 && x11 < x22) && ((y21 > y11 && y21 < y12) || (y22 > y11 && y22 < y12))) return true;
    if ((x12 > x21 && x12 < x22) && ((y21 > y11 && y21 < y12) || (y22 > y11 && y22 < y12))) return true;
    
    //全包围
    if ((x21 <= x11 && x22 >= x12) && (y21 <= y11 && y22 >= y12)) return true;
    if ((x11 <= x21 && x12 >= x22) && (y11 <= y21 && y12 >= y22)) return true;
    
    //交叉
    if ((x11 <= x21 && x12 >= x22) && (y11 >= y21 && y12 <= y22)) return true;
    if ((x21 <= x11 && x22 >= x12) && (y21 >= y11 && y22 <= y12)) return true;
    
    //有一条边相等的情况
    if ((x11 == x21 || x12 == x22) && (y11 < y22 && y12 > y21)) return true;
    if ((y11 == y21 || y12 == y22) && (x11 < x22 && x12 > x21)) return true;
    
    return false;
}
```
