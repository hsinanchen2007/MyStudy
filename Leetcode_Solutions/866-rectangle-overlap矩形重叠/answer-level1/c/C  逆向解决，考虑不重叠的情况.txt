### 解题思路
此处撰写解题思路
// 先考虑没有重叠, 没有重叠的话，可以分为四种情况，假设红色矩形为A，绿色矩形为B，
// 那么B可以分别在A的上、下、左、右四种情况。
### 代码

```c

typedef struct {
    int x;
    int y;
} Point;

// 先考虑没有重叠, 没有重叠的话，可以分为四种情况，假设红色矩形为A，绿色矩形为B，
// 那么B可以分别在A的上、下、左、右四种情况。
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size)
{
    if (rec1 == NULL || rec1Size == 0) {
        return false;
    }

    if (rec2 == NULL || rec2Size == 0) {
        return false;
    }

    Point rec1Point1 = {rec1[0], rec1[1]};
    Point rec1Point2 = {rec1[2], rec1[3]};

    Point rec2Point1 = {rec2[0], rec2[1]};
    Point rec2Point2 = {rec2[2], rec2[3]};

    if (rec1Point2.y <= rec2Point1.y || rec1Point1.y >= rec2Point2.y
        || rec1Point1.x >= rec2Point2.x || rec1Point2.x <= rec2Point1.x) {
        return false;
    }

    return true;
}
```