```
class Solution {
public:
    int climbStairs(int n) {
        int oneStepsDistance = 0, twoStepsDistance = 0;
        if (n <= 2) return 0;
        oneStepsDistance = 2, twoStepsDistance = 1;
        for (int i = 3; i < n; i++) {
            int temp = oneStepsDistance;
            oneStepsDistance += twoStepsDistance;
            twoStepsDistance = temp;
        }
        return oneStepsDistance + twoStepsDistance;
    }
};
```
