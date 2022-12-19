### 解题思路
把题目描述成这样也是没谁了，没有意义的题目！

记录每个括号元素的深度，深度为奇数的赋值为1， 深度为偶数的赋值为0。

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxDepthAfterSplit(char * seq, int* returnSize){
    int i, depth=0, len=strlen(seq);
    int* nums = malloc(sizeof(int) * len);

    for(i=0; i<len; i++){
        if(seq[i] == '('){
            depth++;
            nums[i] = depth;
        }
        
        if(seq[i] == ')'){
            nums[i] = depth;
            depth--;
        }

        nums[i] = nums[i]%2;
    }

    *returnSize = len;
    return nums;
}
```