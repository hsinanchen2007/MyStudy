![image.png](https://pic.leetcode-cn.com/95a3c22fe1b49556ac4a52b81bbe6b811e70193702eee06f6d7f47fccafdc710-image.png)

```
int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
    int *result = malloc(numsSize * sizeof(int));
    int sTop = 0;
    int *sArr = malloc((numsSize + 1) * sizeof(int));  /* 构造栈，index从1开始 */
    int flag = 0;  /* 循环标记 */

    memset(sArr, -1, (numsSize + 1) * sizeof(int));
    memset(result, -1, numsSize * sizeof(int));

    for (int i = 0; i < numsSize; i++) {
        while (sTop != 0 && nums[sArr[sTop]] < nums[i]) { /*构造单调栈*/

            result[sArr[sTop]] = nums[i];
            sTop--;            
        }

        if (flag == 0) { /* 不循环入栈，节省空间 */
            sArr[++sTop] = i;
        }

        if (flag == 0 && i == numsSize - 1) {
            i = -1;  /* 为了匹配i++ */
            flag = 1;
        }
    }
    
    *returnSize = numsSize;
    return result;
}
```
