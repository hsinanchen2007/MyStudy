解题思路：见leetcode官方解释
```
int nthUglyNumber(int n){
    int p2 = 0, p3 = 0, p5 = 0, pu = 1, uNums[n], nums[3], ugly;

    uNums[0] = 1;
    while (pu < n) {
        nums[0] = uNums[p2] * 2;
        nums[1] = uNums[p3] * 3;
        nums[2] = uNums[p5] * 5;
        ugly = nums[0] < nums[1] ? nums[0] : nums[1];
        ugly = ugly < nums[2] ? ugly : nums[2];

        if (ugly == nums[0]) {
            p2++;
        }
        if (ugly == nums[1]) {
            p3++;
        }
        if (ugly == nums[2]) {
            p5++;
        }
        uNums[pu++] = ugly;
    }

    return uNums[pu-1];
}
```
