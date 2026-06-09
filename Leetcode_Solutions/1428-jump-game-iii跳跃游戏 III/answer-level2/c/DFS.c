### 解题思路
1、设置vist为false；
2、按照题目中条件进行递归搜索
![image.png](https://pic.leetcode-cn.com/ab2fae87768a580463d3c003a438750ec20492babe859842fb858173699327cb-image.png)

### 代码

```c
static bool GetRes(int *arr, int arrSize, int index, bool *vist)
{
    if ((index >= arrSize) || (index < 0) || vist[index] == true) {
        return false;
    }

    if (arr[index] == 0) {
        return true;
    }
    vist[index] = true;
    return (GetRes(arr, arrSize, index - arr[index], vist) || GetRes(arr, arrSize, index + arr[index], vist));
}


bool canReach(int* arr, int arrSize, int start)
{
    bool vist[arrSize];
    memset(vist, 0, sizeof(bool) * arrSize);
    return GetRes(arr, arrSize, start, vist);
}
```