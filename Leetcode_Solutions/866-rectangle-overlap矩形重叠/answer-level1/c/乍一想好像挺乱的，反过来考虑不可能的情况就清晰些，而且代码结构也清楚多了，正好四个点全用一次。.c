### 解题思路
乍一想好像挺乱的，反过来考虑不可能的情况就清晰些，而且代码结构也清楚多了，正好四个点全用一次。

### 代码

```c
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    if (rec2[2] <= rec1[0]) {
        return false;
    }
    if (rec2[0] >= rec1[2]) {
        return false;
    }
    if (rec2[1] >= rec1[3]) {
        return false;
    }
    if (rec2[3] <= rec1[1]) {
        return false;
    }
    return true;
}
```