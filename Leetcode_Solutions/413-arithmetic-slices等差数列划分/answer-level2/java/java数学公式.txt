```
public int numberOfArithmeticSlices(int[] A) {
        if (A.length < 3)
            return 0;
        int ans = 0;
        int curlen = 2;
        int curnum = A[1] - A[0];
        for (int i = 2; i < A.length; i++) {
            if (A[i] - A[i - 1] == curnum)
                curlen++;
            else {
                if (curlen > 2) {
                    ans += (curlen - 2) * (curlen - 1) / 2;
                }
                curnum = A[i] - A[i - 1];
                curlen = 2;
            }
        }
        if (curlen > 2) {
            ans += (curlen - 2) * (curlen - 1) / 2;
        }
        return ans;
    }
```
如果题目说可以不连续那就比这个难了
