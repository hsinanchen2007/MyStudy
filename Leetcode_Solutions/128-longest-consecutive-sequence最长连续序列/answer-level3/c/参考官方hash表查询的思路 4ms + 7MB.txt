### 解题思路
设一个基本除数，构建一个简单的hash映射。

### 代码

```c
#define HASH_BASE  (10031)

int hash_index(int a)
{
    int t;
    
    t = a % HASH_BASE;
    if (t < 0) {
        t = HASH_BASE + t;
    }
    return t;
}

int longestConsecutive(int* nums, int numsSize){
    int i, cnt, lmax, cur;
    bool *hs;

    hs = malloc(sizeof(bool) * (HASH_BASE));
    memset(hs, 0, sizeof(bool) * (HASH_BASE));

    for (i = 0; i < numsSize; i++) {
        hs[hash_index(nums[i])] = true;
    }

    lmax = 0;
    for (i = 0; i < numsSize; i++) {
        if (!hs[hash_index(nums[i] - 1)]) {
            cnt = 1;
            cur = nums[i];
            while (hs[hash_index(cur + 1)]) {
                cnt++;
                cur++;
            }
            if (cnt > lmax) {
                lmax = cnt;
            }
        }
    }
    free(hs);
    return lmax;
}
```