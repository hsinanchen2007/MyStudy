### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int i = 0;
    bool t = 0;
    *returnSize = digitsSize;
    for(i = 0; i < digitsSize && digits[i] == 9; i++);/*判断数组是否全为9，这涉及到数组大小的问题*/
    if(digitsSize == i){/*此时数组大小需要+1，需要另外开设一个数组*/
        int* ret = (int*)malloc((digitsSize + 1) * sizeof(int));
        ret[0] = 1;
        for(i = 1; i <= digitsSize; i++){
            ret[i] = 0;
        }
        *returnSize += 1;
        return ret;
    }
    //下面是数组大小不需要变得
    i = digitsSize - 1;
    do{
        digits[i] = (digits[i] + 1) % 10;
        if(digits[i])t = 0;
        else t = 1;
        i--;
    }while(i >= 0 && t);
    return digits;
}
```