很麻烦，不如直接用单调栈简单，很多细节想不清楚，需要调试的时候才能发现。
如果使用栈，遇到小的高度，可以先取当前栈顶的height，然后弹栈，弹栈后可以取到下一层的index，计算一次面积需要用到两层的数据，这是难点所在
```
static int stack(int *heights, int n, int *pos, int last)
{
    int max = 0;
    int curr;
    while (*pos < n) {
        if (last >= 0 && heights[last] >= heights[*pos]) {
            return max;
        }

        curr = *pos; // curr是栈中记录的数据，更新curr即是压站
        *pos += 1;
        // 要用上一层记录的index计算面积，需要将上一层的index传入这一层
        // 这一层的index传入下一层，如果是单调栈则可以先弹栈再读取栈顶
        // 如果递归也用这种方法，需要将当前层的height作为返回值弹栈时带出去
        int area = stack(heights, n, pos, curr); 
        max = (max > area) ? max : area;
        area = heights[curr] * (*pos - 1 - last);
        max = (max > area) ? max : area;
    }
    return max;
}

int largestRectangleArea(int *heights, int n)
{
    int pos = 0;
    return stack(heights, n, &pos, -1);
}
```
