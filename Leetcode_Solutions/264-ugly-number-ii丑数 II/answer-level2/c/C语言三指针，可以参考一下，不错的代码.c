int nthUglyNumber(int n){
    int index = 1;
    int *uglyNum = (int *)malloc(n * sizeof(int));
    uglyNum[0] = 1;
    int i0 = 0;
    int i1 = 0;
    int i2 = 0;
    int ugly = uglyNum[0];
    int nums[3];

    while (index < n) {
        nums[0] = uglyNum[i0] * 2;
        nums[1] = uglyNum[i1] * 3;
        nums[2] = uglyNum[i2] * 5;

        ugly = nums[0] < nums[1] ? nums[0] : nums[1];
        ugly = ugly < nums[2] ? ugly : nums[2];
        if (ugly == nums[0]) {
            i0++;
        }
        if (ugly == nums[1]) {
            i1++;
        }
        if (ugly == nums[2]) {
            i2++;
        }
        uglyNum[index++] = ugly;
    }
    free(uglyNum);
    
    return ugly;
}