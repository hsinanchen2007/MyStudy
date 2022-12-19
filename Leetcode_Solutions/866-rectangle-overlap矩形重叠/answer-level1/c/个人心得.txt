### 解题思路
看了大佬们的思路之后，才知道自己有多么菜。
最开始我想通过点是否在一个矩形内去判断是否相交，结果是判定太多，反而出了错。
另外，反向思考也差了火候，如果考虑不相交的情况要简单一些。
最后，整体法会比单个点去找思路清晰。
### 代码

```c
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    if(rec1[1]>=rec2[3])//在上方
        return false;
    if(rec1[3]<=rec2[1])//在下方
        return false;
    if(rec1[0]>=rec2[2])//在右方
        return false;
    if(rec1[2]<=rec2[0])//在左方
        return false;

    return true;
}
```