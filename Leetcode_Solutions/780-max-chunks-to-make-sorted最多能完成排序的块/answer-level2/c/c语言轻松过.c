### 解题思路
由于该数组的特殊性，要看到某个点 i 能不能切分，就看它和左边区间 [ :i] 里的最大值是不是和 i 本身相同。

如果是就可以切分，如果不是说明肯定还有更大的值在其中，需要换到更后面的位置，就不能在该处切分。

### 代码

```c
int maxChunksToSorted(int* arr, int arrSize){
    int leftmax = arr[0];
    int i = 0;
    int res = 0;

    for (i = 0; i < arrSize; ++i) {
        if (leftmax < arr[i]) {
            leftmax = arr[i];
        }

        if (leftmax == i) {
            res ++;
        }
    }

    return res;
}
```