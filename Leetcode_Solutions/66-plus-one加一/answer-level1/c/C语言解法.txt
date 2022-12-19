执行用时 :4 ms, 在所有 c 提交中击败了80.05%的用户
内存消耗 :7 MB, 在所有 c 提交中击败了48.76%的用户

```
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int length = digitsSize;
    int i = 0;
    int add_num = 1;
    int flag = 0;
    int tmpValue = 0;
    int *return1 = (int *)malloc(sizeof(int)*length);
    int *return2 = (int *)malloc(sizeof(int)*(length + 1));
    for(i = length - 1;i >= 0;i--)
    {
        tmpValue = digits[i] + add_num;
        if(tmpValue >= 10)
        {
            add_num = 1;
           return1[i] = 0;
           return2[i+1] = 0;
        }
        else
        {
            add_num = 0;
            return1[i] = tmpValue;
            return2[i+1] = tmpValue;
        }
        if((i == 0)&&(add_num == 1))
        {
            flag = 1;
        }
    }
    if(flag == 1)
    {
        *returnSize = length + 1;
        return2[0] = 1;
        free(return1);
        return return2;
    }
    else{
        *returnSize = length;
       free(return2);
       return return1; 
    }
}
```
