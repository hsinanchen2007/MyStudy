### 解题思路
1.建立数组求出每个人的年龄；
2.建立hash数组，求出每一年的生存人数；
3.遍历数组，找出最大值及下标。

### 代码

```c
#define ARRAY_SIZE 101

int maxAliveYear(int* birth, int birthSize, int* death, int deathSize)
{
    if (birth == NULL || birthSize == 0 || death == NULL || deathSize == 0) {
        return -1;
    }

    if (birthSize != deathSize) {
        return -1;
    }
    // 1. 求每个人的age
    int* age = (int *)malloc(birthSize * sizeof(int));
    if (age != NULL) {
        memset(age, 0, birthSize * sizeof(int));
    }

    for (int i = 0; i < birthSize; i++) {
        age[i] = death[i] - birth[i];
    }

    // 2. 建立hash数组，求每一年的生存人数
    int* aliveCount = (int *)malloc(ARRAY_SIZE * sizeof(int));
    if (aliveCount != NULL) {
        memset(aliveCount, 0, ARRAY_SIZE *sizeof(int));
    }

    for (int i = 0; i < birthSize; i++) {
        int birthYear = birth[i];
        for (int j = birthYear; j <= (birthYear + age[i]); j++ ) {
           aliveCount[j - 1900]++; 
        }
    }

    // 3. 遍历aliveCount，找出最大值
    int maxCount = aliveCount[0];
    int resultYear = 0;
    for (int i = 1; i < ARRAY_SIZE; i++) {
        if (aliveCount[i] > maxCount) {
            maxCount = aliveCount[i];
            resultYear = i;
        }
    }

    if (age != NULL) {
        free(age);
    }
    if (aliveCount != NULL) {
        free(aliveCount);
    }
    return resultYear + 1900;
}
```