### 解题思路
1 第一次遍历判断是否存在正数，如果没有找到最大的数直接返回
2 如果存在整数。从左开始遍历找到第一个整数。右侧指针向右滑动，滑动一次计算一下累加和，如果累加和大于之前的最大累加和，那么设置最大累加和为当前累加和。如果累加和大于0，那么右侧指针可以继续向右滑动，否则让起始指针等于右侧区间指针。从1重新开始循环

### 代码

```c
int maxSubArray(int* array, int length){
    
    bool hasPositiveValue = false;
    int tmpSstart = 0;
    int negMaxValue = array[0];
    while (tmpSstart < length) {
        if (array[tmpSstart] >0) {
            hasPositiveValue = true;
            break;
        }
        else {
            if (negMaxValue < array[tmpSstart]) {
                negMaxValue = array[tmpSstart];
            }
        }
        tmpSstart++;
    }
    
    if ( !hasPositiveValue) {
        return negMaxValue;
    }
    
    
    int start = 0;
    int right = 0;
    int tmpMaxValue = 0;
    int currentArrayValue = 0;
    while (start < length && right < length) {
        if (array[start] <0) {
            start++;
            right = start;
            continue;
        }
        if (start == right) {
            currentArrayValue = array[start];
            if (currentArrayValue > tmpMaxValue) {
                tmpMaxValue = currentArrayValue;
            }
            right++;
            while (right < length) {
                currentArrayValue = currentArrayValue + array[right];
                if (currentArrayValue > 0) {
                    right++;
                    if (currentArrayValue > tmpMaxValue) {
                        tmpMaxValue = currentArrayValue;
                    }
                }
                else {
                    start = right;
                    right = right;
                    currentArrayValue = 0;
                    break;
                }
            }
        }
    }
    
    return tmpMaxValue;
}
```