**思路**
    为了保证最后输出的结果最小，分析可知尽量让数值大的分布在较高的节点处，这样计算非叶节点值的时候会用到这个较大数值的次数就相对比较少了。
    以此分析，以最大数值为分界点，把树分为左子树和右子树，分别计算非叶节点的和即可。
```
int GetMaxIdx(int *arr, int arrSize)
{
    int max = arr[0];
    int out = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > max) {
            max = arr[i];
            out = i;
        }
    }   
    return out;
}

int CalcMin(int *arr, int arrSize)
{
    /* 1、得到数组中最大成员序号 */
    if (arrSize == 2) {
        return arr[0] * arr[1];
    }
    if (arrSize == 1) {
        return 0;
    }
    int finalOut = 0x7fff;
    int Idx = GetMaxIdx(arr, arrSize);
    //printf("maxIdx = %d\n", Idx);
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == arr[Idx]) {
            int out = 0;
            int maxIdx = i;
            /* 最大数值在两端点的情况 */
            if (maxIdx == 0) {
                int secMax = GetMaxIdx(arr + 1, arrSize - 1);
                out = (arr + 1)[secMax] * arr[maxIdx];
                out += CalcMin(arr + 1, arrSize - 1);
                return out;
            } else if (maxIdx == arrSize - 1) {
                int secMax = GetMaxIdx(arr, arrSize - 1);
                out = arr[secMax] * arr[maxIdx];
                out += CalcMin(arr, arrSize - 1);
                return out;
            } else {
                int leftMax = GetMaxIdx(arr, maxIdx); // 左侧最大值索引
                int rightMax = GetMaxIdx(arr + maxIdx + 1, arrSize - maxIdx - 1); // 右侧最大值索引
                int left = arr[leftMax];
                int right = (arr + maxIdx + 1)[rightMax];
                /* 根据次大的数值选择最大数值位于左子树还是右子树 */
                if (left > right) { 
                    out = left * arr[maxIdx]; //次大数值在左侧，那最大数值放在右子树。
                    out += CalcMin(arr + maxIdx, arrSize - maxIdx);
                    out += CalcMin(arr, maxIdx);
                } else if (left < right) {
                    out = right * arr[maxIdx];
                    out += CalcMin(arr + maxIdx + 1, arrSize - maxIdx - 1);
                    out += CalcMin(arr, maxIdx + 1);
                } else {  // 如果次大数值在最大数值的两侧都有，那就都计算一遍比较哪种比较小
                    out = left * arr[maxIdx];
                    out += CalcMin(arr + maxIdx, arrSize - maxIdx);
                    out += CalcMin(arr, maxIdx);
                    int tmpOut = out;
                    tmpOut += CalcMin(arr + maxIdx + 1, arrSize - maxIdx - 1);
                    tmpOut += CalcMin(arr, maxIdx + 1);
                    if (tmpOut < out) {
                    out = tmpOut;
                    }
                }
            }
            if (finalOut > out) {
                finalOut = out;
            }
        }
    }  
    return finalOut;
}

int mctFromLeafValues(int* arr, int arrSize){
    int out;
    out = CalcMin(arr, arrSize);
    return out;
}
```
