```
class Solution {
    /***********************************************************
    1 2 3 4 5 6 left

    => 

    2 4 6   right         vs         1 2 3 left
    2 4 6   right         =>         6 4 2 left

    => 2 * (3 2 1 left)
    => 2 * (4 - (1 2 3 left))
    => 2 * (6/2 + 1 - (1 2 3 left))      


    Therefore f(6) = 2 * (6/2 + 1 - f(6/2))

    Naive => DP => removed unused
    ***************************************************************/
    public int lastRemaining(int n) {
        return helper(n);
    }

    int helper(int m) {
        if (m == 1) return 1;
        if (m == 2) return 2;
        if (m % 2 != 0) {
            return helper(m - 1);
        }

        return 2 * (m/2 + 1 - helper(m/2));
    }
}
```
