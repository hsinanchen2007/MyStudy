### 解题思路
此处撰写解题思路

### 代码

```c
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    if(rec1[0]>=rec2[2]||rec2[0]>=rec1[2]) return false;
    if(rec1[1]>=rec2[3]||rec2[1]>=rec1[3]) return false;
    return true;
}
```