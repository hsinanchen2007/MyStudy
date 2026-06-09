### 解题思路
先从list1中遍历字符串，如list1与list2字符串如下：
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
先遍历到“Shogun”字符串，然后遍历list2中字符串，由于还未找到目标字符串，所以索引的和还未知，当找到list2中的"Shogun"字符串后，得知索引和为0+3=3;
然后遍历list1中的"Tapioca Express"字符串，注意此时只需要查找list2中的0~2索引即可（也就是"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse"），因为索引和比之前查找到的索引和3小的只需要在list2 0~2中查找字符串即可，以此类推遍历所有list1与list2字符串即可。
![123.PNG](https://pic.leetcode-cn.com/5f12c2c43db5d25546e80a8a48ee21c4e50f92ccf70651c4861a8799b85d45e3-123.PNG)


### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAXS 10240
char ** findRestaurant(char ** list1, int list1Size, char ** list2, int list2Size, int* returnSize){
    int i, j, idxSum, limitJ;
    char **pRes = NULL;
    int record[MAXS] = { 0 };
    limitJ = list2Size;
    idxSum = MAXS;
    *returnSize = 0;
    for (i = 0; i < list1Size; i++) {
        for (j = 0; j < limitJ; j++) {
            if (strcmp(list1[i], list2[j]) == 0) {
                if (idxSum > i + j) {
                    idxSum = i + j;
                    limitJ = j;
                    record[0] = j;
                    *returnSize = 1;
                    break;
                } else if (idxSum == i + j) {
                    limitJ = j;
                    record[*returnSize] = j;
                    (*returnSize)++;
                    break;
                } else {
                    break;
                }
            }
        }
    }

    pRes = (char **)malloc(sizeof(char *) * (*returnSize));
    for (i = 0; i < *returnSize; i++) {
        pRes[i] = (char *)malloc(sizeof(char) * (strlen(list2[record[i]]) + 1));
        memcpy(pRes[i], list2[record[i]], sizeof(char) * strlen(list2[record[i]]));
        pRes[i][strlen(list2[record[i]])] = '\0';
    }
    return pRes;
}
```