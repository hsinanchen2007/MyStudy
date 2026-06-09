### 解题思路
![image.png](https://pic.leetcode-cn.com/27d01823944f84c5ce761649a1df36d70bb2fbd9840d470db4d6ce6bdf391b27-image.png)


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findRestaurant(char ** list1, int list1Size, char ** list2, int list2Size, int* returnSize){
    * returnSize = 0;
    char** ret = (char**)malloc(sizeof(char*) * (fmin(list1Size, list2Size)));
    int i, j;
    int min = INT_MAX;
    for(i = 0; i < list1Size; i++) {
        for(j = 0; j < list2Size; j++) {
            if(strcmp(list1[i], list2[j]) == 0) {
                if(i + j < min) {
                    ret[*returnSize] = list1[i];
                    (*returnSize)++;
                    min = fmin(min, i + j);
                    break;
                } else if(i + j == min) {
                    ret[*returnSize] = list1[i];
                    (*returnSize)++;
                    break;
                } else {
                    break;
                }
            }
        }
    }
    return ret;
}
```