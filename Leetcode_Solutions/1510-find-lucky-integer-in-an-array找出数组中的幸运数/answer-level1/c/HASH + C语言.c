### 解题思路
* 看到数字或者字符根频率相关的，一般使用hash存储。
* 本题2点需要注意，使用max 和 returnMax 来表示。 在遍历时计算出数组中最大的元素max，可以在下面遍历hash数组时，只用遍历到max即可； 
* returnMax,是题目中要求的多个幸运数存在时，返回最大的。
### 代码

```c
int findLucky(int* arr, int arrSize){
    if (arr == NULL || arrSize <= 0) {
        return -1;
    }
    int  hashTmp[10000] = {0};
    int i;
    int max = -1;
    int returnMax = -1;
    for (i = 0; i < arrSize; i++) {
        hashTmp[arr[i]]++;
        max = max < arr[i] ? arr[i] : max;
    }
    
    for (i = 1; i <= max; i++) {
        if (hashTmp[i] == i) {
            returnMax = returnMax < i ? i : returnMax;
        }
    }
    return returnMax == -1 ? -1 : returnMax;
}
```

结果：
![image.png](https://pic.leetcode-cn.com/b9c4171345d1bbed28a2724419fa50b74984d807ad5240ed9ca9b767fed6191a-image.png)
