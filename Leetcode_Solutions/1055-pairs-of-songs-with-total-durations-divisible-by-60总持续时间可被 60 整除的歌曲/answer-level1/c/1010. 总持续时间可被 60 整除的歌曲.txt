### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/c179bbd9b3d5af1652dbd2e8681c6469d44894e07e87c3ed402c8c65f09da88a-image.png)

### 代码

```c
#define HASH_SIZE 60
int* InitHash(int hashSize)
{
    int *hash = (int *)malloc(sizeof(int) * HASH_SIZE);
    for (int i=0; i<hashSize; i++) {
        hash[i] = 0;
    }
    return hash;
}
int numPairsDivisibleBy60(int* time, int timeSize){
    if (time == NULL || timeSize < 1) return 0;

    int *hash = InitHash(HASH_SIZE);

    for (int i = 0; i < timeSize; i++) {
        hash[time[i] % HASH_SIZE]++;
    }

    int sum = 0;
    sum += (hash[0] * (hash[0] - 1))/2;
    sum += (hash[HASH_SIZE/2] * (hash[HASH_SIZE/2] - 1))/2;

    for (int i = 1; i < HASH_SIZE/2; i++) {
        sum += hash[i] * hash[HASH_SIZE - i];
    }
    
    free(hash);
    return sum;
}

/* test case
[30,20,150,100,40]

[60,60,60]

[60]

[0,60,120,180]

[0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,30,29,28,27,26]

[10,20,30,40,50,60,70,80,90,100,110,120,130]
*/
```