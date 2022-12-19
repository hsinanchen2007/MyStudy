### 解题思路
左边和右边比较，下边和上边比较

### 代码

```c
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    int leftx = rec1[0] > rec2[0] ? rec1[0] : rec2[0];
    int lefty = rec1[1] > rec2[1] ? rec1[1] : rec2[1];

    int rightx = rec1[2] > rec2[2] ? rec2[2] : rec1[2];
    int righty = rec1[3] > rec2[3] ? rec2[3] : rec1[3];

    if ((leftx >= rightx) || (lefty >= righty)) {
        return false;
    }
    return true;
}
```