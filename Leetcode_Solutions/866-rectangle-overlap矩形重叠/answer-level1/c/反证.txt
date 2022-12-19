### 解题思路
根据题意，判断rec1只要出现在rec2的上下左右其中一个则返回false，例如左边就是rec1的最大X值小于等于rec2的最小X值。

### 代码

```c
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    if(rec1[2]<=rec2[0]||rec1[1]>=rec2[3]||rec1[0]>=rec2[2]||rec1[3]<=rec2[1])
        return false;
    return true;
}
```