### 解题思路
窗口固定K，其它的差不多，先去重，再计算是否满足条件

### 代码

```c
#define MAX_SIZE 128
int GetWindow(int start, int end)
{
    return end - start + 1;
}
int MAX(int a, int b)
{
    return a < b ? b : a;
}
int numKLenSubstrNoRepeats(char * S, int K){
    int left, right, pos, dupPos;
    int dups[MAX_SIZE] = {0};
    int count;
    int num;
    
    if ((S == NULL) || (S[0] == '\0')) {
        return 0;
    }

    if (strlen(S) < K) {
        return 0;
    }

    left = 0;
    count = 0;
    num = 0;
    for (right = 0; S[right] != '\0'; right++) {
        pos = (int)(S[right]);   
        if (dups[pos] > 0) {
            dupPos = pos;
            while (dups[dupPos] > 0) {
                pos = (int)(S[left]);
                dups[pos]--;    
                left++;
            }
            pos = dupPos; 
        }

        count = GetWindow(left, right);
        dups[pos]++;
        if (count == K) {
            num++;
        } else if (count > K) {
            pos = (int)(S[left]);
            dups[pos]--;    
            left++;
            num++;
        } 
    }

    return num;
}
```