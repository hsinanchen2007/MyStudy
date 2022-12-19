

首次实现采用暴力方式求解，但是最后几个用例的数量级非常大，运行时间超过限制，故需要转换思路

通过查看其它人的解题思路，了解到 可以利用异或的 `A XOR A = 0` 性质，进行计算上的简化

`XOR[Li, Ri] = arr[Li] xor arr[Li+1] xor ... xor arr[Ri]`  
`XOR[0, Ri] = XOR[0, Li-1] xor XOR[Li, Ri]`

故 `XOR[0, Ri] xor XOR[0, Li-1] = XOR[Li, Ri]`，用例亲自计算了一次对原理的理解会比较有效。

通过提前求得给定数组的**所有前缀异或值**，简化运算。

代码实现如下：
```C
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* xorQueries(int* arr, int arrSize, int** queries, int queriesSize, int* queriesColSize, int* returnSize){
    int xor;    
    int *prefixXor = (int *)malloc(sizeof(int) * arrSize);
    memset(prefixXor, 0, sizeof(int) * arrSize);

    int *retArr = (int *)malloc(sizeof(int) * queriesSize);
    memset(retArr, 0, sizeof(int) * queriesSize);

    prefixXor[0] = arr[0];
    for (int i = 1; i < arrSize; i++) {
        prefixXor[i] = prefixXor[i - 1] ^ arr[i];
    }

    for (int i = 0; i < queriesSize; i++) {
        /* XOR[0, Ri] xor XOR[0, Li-1] = XOR[Li, Ri] */
        retArr[i] = prefixXor[queries[i][1]] ^ ((queries[i][0] != 0) ? prefixXor[queries[i][0] - 1] : 0);
    }
    
    free(prefixXor);

    *returnSize = queriesSize;
    return retArr;
}
```

代码中唯独一行需要稍加解释
`retArr[i] = prefixXor[queries[i][1]] ^ ((queries[i][0] != 0) ? prefixXor[queries[i][0] - 1] : 0);`  
XOR[0, Ri]，即 prefixXor[Ri]，但是为了表达式一致性， `prefixXor[Ri]` 与 `prefixXor ^ 0` 相同。

Tips: 三目运算符 优先级 低于 异或