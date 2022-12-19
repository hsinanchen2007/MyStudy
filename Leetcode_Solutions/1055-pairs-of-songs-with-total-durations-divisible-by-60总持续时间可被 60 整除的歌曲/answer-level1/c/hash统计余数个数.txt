### 解题思路
此处撰写解题思路

### 代码

```c
//暴力解超时
// int numPairsDivisibleBy60(int* time, int timeSize){
//     int cnt = 0;
//     for (int i = 0; i < timeSize; i++) {
//         for (int j = i + 1; j < timeSize; j++) {
//             if ((time[i] + time[j]) % 60 == 0) {
//                 cnt++;
//             }
//         }
//     }
//     return cnt;
// }
int numPairsDivisibleBy60(int* time, int timeSize){
    int cnt = 0;
    int hash[60] = {0};
    for (int i = 0; i < timeSize; i++) {
        time[i] %= 60;
        hash[time[i] % 60]++;
    }

    for (int i = 0; i < timeSize; i++) {
        hash[time[i]]--;
        if (time[i] == 0) {
            cnt += hash[time[i]];
        } else {
            cnt += hash[60 - time[i]];
        }
    }
    return cnt;
}
```