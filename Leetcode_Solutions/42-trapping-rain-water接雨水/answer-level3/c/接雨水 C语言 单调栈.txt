### 解题思路
此处撰写解题思路

### 代码

```c
// 单调栈
#define min(a, b) ((a) < (b) ? (a) : (b))
int trap(int* height, int heightSize)
{
    int ans = 0;
    int *stack = (int *)calloc(heightSize, sizeof(int));
    int top = 0;
    for (int i = 0; i < heightSize; i++)
    {
        
        while (top > 0 && height[stack[top - 1]] < height[i])
        {
            // 栈顶弹出时，用cur记录一下
            int cur = stack[--top];
            
            if (top == 0)
                break;
            int l = stack[top - 1];
            int r = i;
            int h = min(height[r], height[l]) - height[cur];
            ans += (r - l - 1) * h;
        }
        
        stack[top++] = i;
    }
    return ans;
}

```