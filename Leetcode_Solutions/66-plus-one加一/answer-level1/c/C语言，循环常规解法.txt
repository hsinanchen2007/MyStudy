### 解题思路
先完成给最后一位加1的操作，然后从后往前判断每个位上的数字是否需要进位，如果存在不需要进位的数字，退出并返回；如果遍历了所有位数，都存在进位，则新建一个数组，大小为digitsSize+1，数组首位为1，其他位拷贝过来就行。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){

    int i=digitsSize-1;
    int carry=0;
    *returnSize=digitsSize;
    digits[i]++;
    while(i>=0){
        if((digits[i]+carry)/10){
            carry=1;
            digits[i]=0;
        }else{
            digits[i]+=carry;
            return digits;
        } 
        i--;
    }
    (*returnSize)++;
    int* result=(int*)malloc(sizeof(int)*(*returnSize));
    *(result++)=1;
    memcpy(result,digits,sizeof(int)*digitsSize);
    return --result;
}
```