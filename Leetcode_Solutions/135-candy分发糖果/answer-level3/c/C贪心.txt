![image.png](https://pic.leetcode-cn.com/cc833936045fd5a650036e75b9d08cc5c6d5a4def7513f9d3442438cc60ea30c-image.png)

```
int candy(int* ratings, int ratingsSize){
    int result = ratingsSize;
    int hash[ratingsSize + 1];

    memset(hash, 0, sizeof(hash));

    /*左邻居*/
    for (int i = 1; i < ratingsSize; i++) {
        if (ratings[i] > ratings[i - 1] && hash[i] < hash[i - 1] + 1) {
            hash[i] = hash[i - 1] + 1;
        }
    }

    /*右邻居*/
    for (int i = ratingsSize - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1] && hash[i] < hash[i + 1] + 1) {
            hash[i] = hash[i + 1] + 1;
        }
    }

    for (int i = 0; i < ratingsSize; i++) {
        result += hash[i];
    }

    return result;
}
```
