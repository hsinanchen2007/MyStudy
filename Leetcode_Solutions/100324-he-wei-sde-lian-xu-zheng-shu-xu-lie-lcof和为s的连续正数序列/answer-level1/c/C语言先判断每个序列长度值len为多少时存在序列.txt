### 解题思路
执行用时 :12 ms, 在所有 C 提交中击败了71.43%的用户  
内存消耗 :7.7 MB, 在所有 C 提交中击败了100.00%的用户  

最开始想到双指针，两个指针之间的连续数相加看是不是和为target。  
但我感觉事情并不是这样简单，肯定能在数学上找到突破。。。  

1. len最长可以为int(sqrt(2*target))。 因为1+2+3+...+len = target时，len这时是最长的。等式左边有关于len的求和公式。
2. 分析每个序列长度len为多少时才能和为target。len除数为偶数情况，只有被target除得的结果为0.5,才存在序列；len除数为奇数情况，只有能被target整除,才存在。
3. 分配空间然后进行赋值操作

代码可能有优化的空间，感觉还不如简单点暴力点。但是写了一半又不想放弃这个方案。

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    int i;
    int start, len;  //start：每个序列的第一个数；len：每个序列的长度
    int maxsize = sqrt(2*target);
    int** result = (int**)malloc(sizeof(int*)*maxsize);
    *returnColumnSizes = (int*)malloc(sizeof(int)*maxsize);

    *returnSize = 0;
    for(len=maxsize; len>1; len--){
        if(len%2==0 && target%len!=0 && (2*target)%len==0){  // 对除数为偶数情况，只有除得的结果为0.5,才存在
            result[*returnSize] = (int*)malloc(sizeof(int)*len);
            start = target/len - (len/2-1);
            for(i=0; i<len; i++){
                result[*returnSize][i] = start++;
            }
            (*returnColumnSizes)[*returnSize] = len;
            (*returnSize)++;
        }else if(len%2==1 && target%len==0){  // 对除数为奇数情况，只有能整除,才存在
            result[*returnSize] = (int*)malloc(sizeof(int)*len);
            start = target/len - len/2;
            for(i=0; i<len; i++){
                result[*returnSize][i] = start++;
            }
            (*returnColumnSizes)[*returnSize] = len;
            (*returnSize)++;
        }
    }
    return result;
}

```