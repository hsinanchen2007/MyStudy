```
class Solution {
    public int addDigits(int num) {
        int ans = num % 9;
        if ((0 == ans) && (0 != num)) ans = 9;
        return ans;
    }
}
```
