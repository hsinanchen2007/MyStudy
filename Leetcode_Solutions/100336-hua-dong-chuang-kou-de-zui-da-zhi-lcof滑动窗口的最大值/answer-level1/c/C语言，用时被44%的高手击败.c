### 解题思路
双端+单调队列

### 代码

```c
void q_in(int* nums, int* q, int qf, int* qe, int k, int idx)
{
    int i = 0;
    if (qf < *qe) {
        for (i = qf; i < *qe; i++) {
            if (nums[idx] > nums[q[i]]) {
                q[i] = idx;
                *qe = (i + 1) % (k + 1);
                return;
            }
        }
    } else if (qf > *qe) {
        for (i = qf; i < k + 1; i++) {
            if (nums[idx] > nums[q[i]]) {
                q[i] = idx;
                *qe = (i + 1) % (k + 1);
                return;
            }
        }

        for (i = 0; i < *qe; i++) {
            if (nums[idx] > nums[q[i]]) {
                q[i] = idx;
                *qe = (i + 1) % (k + 1);
                return;
            }
        }
    }

    if ((*qe + 2 + k - qf) % (k + 1) == 0) {
        return;
    }

    q[*qe] = idx;
    *qe = (*qe + 1) % (k + 1);
}

int* maxSlidingWindow(int* nums, int numsSize, int k, int* returnSize)
{
    if (nums == NULL || numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    int* q = (int*)malloc(sizeof(int) * (k + 1));
    int qf = 0;
    int qe = 0;
    int i = 0;
    int* ret = (int*)malloc(sizeof(int) * (numsSize - k + 1));

    for (i = 0; i < k - 1; i++) {
        q_in(nums, q, qf, &qe, k, i);
    }

    for (i = k - 1; i < numsSize; i++) {
        q_in(nums, q, qf, &qe, k, i);
        ret[i - k + 1] = nums[q[qf]];
        if (q[qf] == i - k + 1) {
            qf = (qf + 1) % (k + 1);
        }
    }

    free(q);
    *returnSize = numsSize - k + 1;
    return ret;
}
```