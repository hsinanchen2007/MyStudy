### 解题思路
使用前缀和，然后将大于8的替换为1，小于等于8的替换为-1，然后查找前缀和最大的数目

### 代码

```c


#define MAX(a,b) a>b?a:b
#define MAX_LEN 10001
int longestWPI(int* hours, int hoursSize){
    int high = 0;
    int low = 0;
    int num = 0;
    int max = 0;

    if (hoursSize == 0) {
        return 0;
    }

    for (int i = 0; i < hoursSize; i++) {
        if (hours[i] > 8) {
            hours[i] = 1;
        } else {
            hours[i] = -1;
        }
    }

    int sum[MAX_LEN] = {0};
    sum[0] = hours[0];

    for (int i = 1; i < hoursSize; i++) {
        sum[i] = hours[i] + sum[i-1];
    }

     for (int i = 0; i < hoursSize; i++) {
         for (int j = 0; j <= i; j++) {
             if (sum[i] - sum[j] + hours[j] > 0) {
                 max = MAX(max, i-j+1);
                 break;
             }
         }
     }

    return max;
}
```