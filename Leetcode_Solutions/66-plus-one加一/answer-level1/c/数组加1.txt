### 解题思路
这类题型关键是用例，有以下几类：
1.正常数234
2.部分进位 19
3.全部进位 999
思路，先给末位+1，然后一个循环考虑进位，如果结果溢出还需分配数组并复制

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    bool c = false;//进位标志
    digits[digitsSize-1]+=1;
    *returnSize=digitsSize;
    for(int i=digitsSize-1;i>=0;i--){
        if(c)digits[i]+=1;
        if(digits[i]>9){
            c=true;
            digits[i]=0;
        }else c=false;
    }
    if(c){
        *returnSize=digitsSize+1;
        printf(" %d",*returnSize);
        int* arr = (int*)malloc(sizeof(int)*(*returnSize));
        arr[0]=1;
        for(int i=1;i<*returnSize;i++)
            arr[i]=digits[i-1];
        return arr;
    }
    return digits;
}
```