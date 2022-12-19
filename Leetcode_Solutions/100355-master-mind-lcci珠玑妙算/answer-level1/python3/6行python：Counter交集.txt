### 解题思路
计数器算出两个颜色个数，然后取交集，即最小。得到的计数器就是颜色相等的（包含cao相等的）
最后再计算**颜色+cao**相等得到猜中，`total-right`就是伪猜中的。

### 代码

```python3 []
class Solution:
    def masterMind(self, solution: str, guess: str):
        from collections import Counter
        total = sum((Counter(solution) & Counter(guess)).values())
        right = sum(1 for (i, j) in zip(solution, guess) if i == j)
        return [right, total - right]
```
```c []
int* masterMind(char* solution, char* guess, int* returnSize){
    short guessBucket[26] = {0}, solutionBucket[26] = {0}, i;
    *returnSize = 2;
    int *res = (int *)calloc(2, sizeof(int));
    for (i = 0; i < 4; i++) {
        if (solution[i] != guess[i]) {  // 不相等的才统计
            guessBucket[guess[i]-65]++;
            solutionBucket[solution[i]-65]++;
        } else res[0]++;  // 统计完全猜中的
    }
    for (i = 0; i < 26; i++) {  // 最后计算伪猜中的
        if (guessBucket[i] > 0 && solutionBucket[i] > 0) {
            res[1] += guessBucket[i] > solutionBucket[i] ? solutionBucket[i] : guessBucket[i];
        }
    }
    return res;
}
```