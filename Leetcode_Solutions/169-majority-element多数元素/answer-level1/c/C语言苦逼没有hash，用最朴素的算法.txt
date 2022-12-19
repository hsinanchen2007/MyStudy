先说一个假设，比如[3,3,1,1,1,2,2]
如果从nums[0]开始数，3的个数少于一半，则从nums[1]开始数，3的个数肯定也小于一半。
因此两层遍历，第一层找到一个数作为起点，第二层从它后面一个数开始计数，如果数量大于一半，则return。
**直接这样做能得到答案，但是最后一个用例会超时。**
考虑减掉一些冗余的计算：假如3已计算一次，且不足一半，那么后面再遇到3则可直接跳过。
用一个bit数组来保存这个visit状态即可。
```c
static inline void setMap(char *map, int i)
{
    int a = i >> 3;
    int b = i - (a << 3);
    map[a] = map[a] | (1 << b);
    return;
}
static inline bool isTrue(char *map, int i)
{
    int a = i >> 3;
    int b = i - (a << 3);
    return ((map[a] & (1 << b)) != 0);
}
int majorityElement(int* nums, int numsSize)
{
    if (numsSize == 1) return nums[0];
    int half = numsSize / 2;
    char *map = malloc(numsSize / 8 + 1);
    memset(map, 0, numsSize / 8 + 1);
    for (int i = 0; i < (numsSize - 1); i++) {
        if (isTrue(map, i)) {
            continue;
        }
        int x = nums[i];
        int count = 1;

        for (int j = i + 1; j < numsSize; j++) {
            if (x == nums[j]) {
                count++;
                setMap(map, j);
                if (count > half) {
                    return x;
                }
            }
        }
    }
    return 0;
}
```

![image.png](https://pic.leetcode-cn.com/72c28f022d80a4f2e9f583e0f292a3c6ae4e4d85b63e4092827269fa338e1d51-image.png)
