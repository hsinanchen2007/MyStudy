### 解题思路
参考其他人思路，分两步完成：
1、二分查找，寻找转折点，确定搜索区间
2、二分查找，找到符合条件的最小序列

### 代码

```c
int search(int* arr, int arrSize, int target){
    if (arrSize == 0)
        return -1;
    
    int left, right, mid;
    
    // 二分查找，找到转折点
    left = 0;
    right = arrSize - 1;
    while (left < right) {
        mid = (left + right) / 2;
        if (arr[mid] <= arr[right])
            right = mid;
        else if (arr[mid] >= arr[left])
            left = mid + 1;  
    }

    // 分成两部分处理
    if (target >= arr[0]) {
        left = 0;
        right = mid;
    } else {
        left = mid + 1;
        right = arrSize - 1;
    }
    
    // 相同值返回最前面的部分
    while (left < right) {
        mid = (left + right) / 2;
        if (arr[mid] >= target)
            right = mid;
        else
            left = mid + 1;
    }
        
    if (arr[left] == target)
        return left;
    return -1;
}
```