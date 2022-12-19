### 解题思路
恰巧昨天刷到一个类似的题。
时间92，内存100.
建立一个10001长度的数组，全设为0
将输入的数组遍历，数组对应位置++
然后输出数组的前k个数字

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    int t[10001] = {0};
    for(int i=0;i<arrSize;i++)
        ++t[arr[i]];
    *returnSize = k;
    int *ans = (int*)malloc(sizeof(int)*k);
    int i=0,cou=0;
    while(k!=0||i>=10001){
        if(t[i]>0){
            ans[cou++] = i;
            k--;
            t[i]--;
        }
        else i++;   
    }
    return ans;
}
```