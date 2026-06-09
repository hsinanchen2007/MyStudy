java 递归迭代0ms 击败100%

```
class Solution {
    public int numberOfSteps (int num) {
        int count = 0;
        while (num > 0) {
            if (num % 2 == 0) {
                num = num / 2;
            }else {
                num = num - 1;
            }
            count++;
        }
        return count;
    }
}
```