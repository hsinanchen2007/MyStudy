### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/e92f718089a6a5d53946f506b6b3d6de9589df78573041b6c5eea2931355317c-image.png)
1) 注意 min_x = max_x，表示矩形2的左侧和矩形1的右侧重叠，或者矩形2本身就是1条直线
2) 同理，y轴上的线可以类推
3) 排除掉两种错误情况，剩余的情况就是true
4) 做题有技巧，看错误的多，还是正确的多，一般就写少的条件，另外的就让else去计算吧
### 代码

```c
int get_min(int a, int b)
{
    return a < b ? a: b;
}

int get_max(int a, int b)
{
    return a > b ? a: b;
}

bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    int min_x = get_max(rec1[0], rec2[0]);
    int min_y = get_max(rec1[1], rec2[1]);
    int max_x = get_min(rec1[2], rec2[2]);
    int max_y = get_min(rec1[3], rec2[3]);

    if (min_x >= max_x) {
        return false;
    }
    if (min_y >= max_y) {
        return false;
    }

    return true;
}
```