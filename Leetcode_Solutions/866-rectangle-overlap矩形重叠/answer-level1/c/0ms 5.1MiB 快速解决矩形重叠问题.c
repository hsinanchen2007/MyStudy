### 解题思路
此处撰写解题思路
    对立面解题法。正面解题方法可以看我的py3的思路。
### 代码

```c
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    if(rec1[0]>=rec2[2] || rec1[2]<=rec2[0])return false;
    if(rec1[1]>=rec2[3] || rec1[3]<=rec2[1])return false;
    return true;
}
```