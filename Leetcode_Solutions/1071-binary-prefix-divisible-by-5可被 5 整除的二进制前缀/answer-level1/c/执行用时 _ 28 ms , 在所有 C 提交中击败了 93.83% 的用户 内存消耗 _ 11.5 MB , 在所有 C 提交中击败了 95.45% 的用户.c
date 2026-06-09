### 解题思路
简单的二进制转十进制后判断
出现问题：1.越位2.超时
解决方法：随着数组后移位数增多，之前的数据都将作为跟高位前移比如temp = temp*2+A[i];
若temp-10,则总体减去10*（2的n次方），不影响后续判断剩下的是否可被5整除。
所以我们每当十进制大于10则减10可解决越位问题；
从此我们每次计算选取前者个位直接预算，（temp%10）*2+A[i];可解决超时问题。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* prefixesDivBy5(int* A, int ASize, int* returnSize){
    bool *answer = (bool*)malloc(sizeof(bool)*ASize);
    *returnSize = ASize;
    int temp = 0;
    for(int i = 0;i<ASize;i++){
        temp = temp*2+A[i];
        if(temp%5 == 0)
            answer[i] = true;
        else
            answer[i] = false;
        temp = temp%10;
    }
    return answer;
}
```