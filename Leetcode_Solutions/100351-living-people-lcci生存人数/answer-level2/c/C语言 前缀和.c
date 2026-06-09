```
int maxAliveYear(int* birth, int birthSize, int* death, int deathSize){
    int a[2001] = { 0 };
    for (int i = 0; i < birthSize; i++) {
        a[birth[i]-1900]++;
        a[death[i]-1900+1]--;
    }
    int max = 0;
    int year = 0;
    int temp = 0;
    for (int i = 0; i<2001; i++) {
        temp += a[i];
        if (max < temp) {
            max = temp;
            year = i;
        }

    }
    return year+1900;
}
```
前缀和
当作公交上下车，如果出生则在出生年加一，如果死亡则在死亡后的一年减一，对数组遍历一遍即可找出最大出生人数所在的年份