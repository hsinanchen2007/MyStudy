### 解题思路
固定滑动窗口

### 代码

```c
int dietPlanPerformance(int* calories, int caloriesSize, int k, int lower, int upper){
    int score = 0;
    int sum = 0;
    for (int i = 0; i < k; i++) {
        sum += calories[i];
    }
    if (sum < lower) {
        score -= 1;
    }
    if (sum > upper) {
        score += 1;
    }
    for (int i = 1; i < caloriesSize - k + 1; i++) {
        sum = sum - calories[i-1] + calories[i + k - 1];
        if (sum < lower) {
            score -= 1;
        }
        if (sum > upper) {
            score += 1;
        }
    }
    return score;
}
```