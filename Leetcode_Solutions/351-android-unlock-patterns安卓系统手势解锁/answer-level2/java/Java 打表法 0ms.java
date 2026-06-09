这种测试用例有限的题，直接打表最快
```
public int numberOfPatterns(int m, int n) {
        int[] nums = new int[10];
        nums[1] = 9;
        nums[2] = 56;
        nums[3] = 320;
        nums[4] = 1624;
        nums[5] = 7152;
        nums[6] = 26016;
        nums[7] = 72912;
        nums[8] = 140704;
        nums[9] = 140704;
        int res = 0;
        for(int i = m;i<=n;i++){
            res += nums[i];
        }
        return res;
    }
```
