```
#define MAXSIZE 1000
int g_array[MAXSIZE];
int g_arrayNum = 0;

void SubFuncPush(int index)
{
    g_array[g_arrayNum] = index;
    g_arrayNum++;
}

void SubFuncPop()
{
    if (g_arrayNum > 0) {
        g_arrayNum--;
    } 
}

int SubFuncTop()
{
    return g_array[g_arrayNum - 1];
}

int MaxVal(int a, int b)
{
    return a > b ? a : b;
}

int largestRectangleArea(int* heights, int heightsSize)
{
    SubFuncPush(-1);
    SubFuncPush(0);
    int i;
    int returnMaxVal = 0;
    int tmpHeights;
    for (i = 1; i < heightsSize; i++) {
        while ((g_arrayNum >= 1) && (heights[SubFuncTop()] > heights[i])) {
            printf("mmmmm\n");
            tmpHeights = heights[SubFuncTop()];
            SubFuncPop();
            returnMaxVal = MaxVal(returnMaxVal, tmpHeights * (i - SubFuncTop() - 1));
            printf("returnMaxVal: %d\n", returnMaxVal);
        }
        SubFuncPush(i);
    }
    printf("tttt\n");
    int tmpIndex = SubFuncTop();
    while(SubFuncTop() != -1) {
        SubFuncPop();
        returnMaxVal = MaxVal(returnMaxVal, heights[tmpIndex] * (tmpIndex + 1 - (SubFuncTop() - 1) - 1));
    }

    return returnMaxVal;
}
```
