```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    int* ans = NULL;
    *returnSize = 0;
    if (arrSize == 0 || k == 0) return ans;

    int ipos, ppos; // ppos保存ipos的parent的位置

    ans = (int*)malloc(k * sizeof(int));
    for (int i = 0; i < k; ++i) { // 维护一个保存k个int元素且顶端元素最大的heap
        ans[i] = arr[i];
        
        ipos = i;
        ppos =  (ipos - 1) / 2;
        while (ipos > 0 && ans[ppos] < ans[ipos]) {
            int temp = ans[ipos];
            ans[ipos] = ans[ppos];
            ans[ppos] = temp;

            ipos = ppos;
            ppos = ppos =  (ipos - 1) / 2;
        }
    }

    int lpos, rpos, mpos; // lpos和rpos分别保存ipos的左右child的位置
    for (int i = k; i < arrSize; ++i) {
        if (arr[i] < ans[0]) { // 每当arr[i]小于heap的顶端元素时，将顶端元素置换为arr[i]
            ans[0] = arr[i];

            ipos = 0;
            while (1) {
                lpos = 2 * ipos + 1;
                rpos = 2 * ipos + 2;

                if (lpos < k && ans[lpos] > ans[ipos]) {
                    mpos = lpos;
                }
                else {
                    mpos = ipos;
                }

                if (rpos < k && ans[rpos] > ans[mpos]) {
                    mpos = rpos;
                }

                if (mpos == ipos) {
                    break;
                }
                else {
                    int temp = ans[ipos];
                    ans[ipos] = ans[mpos];
                    ans[mpos] = temp;

                    ipos = mpos;
                }
            }
        }
    }
    *returnSize = k;
    return ans;
}
```
