### 解题思路
暴力暴力法

### 代码

```c
int largestRectangleArea(int* heights, int heightsSize){
    int max = 0;
    int tmp = 0;
    int slow = 0;
    int fast = 0;
    int minheight = 0;

    for (slow = 0; slow <= heightsSize - 1; slow++)
    {
        minheight = heights[slow];

        for (fast = slow; fast <= heightsSize - 1; fast++)
        {
            minheight = heights[fast] < minheight ? heights[fast] : minheight;
            tmp = minheight * (fast - slow + 1);
            max = tmp > max ? tmp : max;
        }
    }

    return max;
}

```