### 解题思路
    反向思考比较好求解。

### 代码

```c
inline bool HasIntersection(int a1, int a2, int b1, int b2)
{
    if (b1 >= a2) {
        return false;
    }
    if (b2 <= a1) {
        return false;
    }
    return true;
}

bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    if (!rec1 || rec1Size <= 0 || !rec2 || rec2Size <= 0) {
        return false;
    }
    if (!HasIntersection(rec1[0], rec1[2], rec2[0], rec2[2]) || !HasIntersection(rec1[1], rec1[3], rec2[1], rec2[3])) {
        return false;
    }
    return true;
}
```