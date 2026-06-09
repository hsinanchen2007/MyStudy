### 解题思路
建立数组模拟

### 代码

```c
int minIncrementForUnique(int* A, int ASize){
    if (ASize == 0 || ASize == 1)  return 0;
    int isExisted[100005] = {0};
    int doubled[100005] = {0};
    int cnt = 0;
    isExisted[A[0]] = 1;
    for (int i = 1; i < ASize; i++) {
        if (isExisted[A[i]]) { //如果已存在，把该数字放进已重复数组里
            doubled[cnt++] = A[i];
        } else {
            isExisted[A[i]] = 1; //记录每一个存在的数
        }
    }
    int ans = 0;
    for (int i = 0; i < cnt; i++) {
        for (int j = (doubled[i] + 1); ;j++) {
            if (!isExisted[j]) { //从每个数加1开始，找到第一个未存在过的大于它的数
                isExisted[j] = 1; //使该数“已存在”
                ans += (j - doubled[i]); //其差值即为最小加一次数
                break;
            }
        }
    }
    return ans;
}
```