### 解题思路
暴力破解法：
1.建立一个结构体，里面存旧的字符，然后和排好序的字符
2.然后对这个结构体进行排序，这样结构体里面的字符都是排好序的
3.将排好序的结构体数组第一个开始挑选一样的字符，并且将此结构体内的旧的字符存到答案里面。
此解法比较简单，因为都是用了快排的库函数强sort

### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 typedef struct Node{
     char *old1;
     char *new1;
 }Node;
 int cmp1(const void *a, const void *b)
 {
     return *(char *)a - *(char *)b;
 }
 
 int cmp2(const void *a, const void *b)
 {
     Node node1 = *(Node*)a;
     Node node2 = *(Node*)b;
     return strcmp(node1.new1, node2.new1);
 }

 void arrayOneStr(char ** strs, int strsSize, Node *nodeArray)
 {
     for (int i = 0; i < strsSize; i++) {
         int len = strlen(strs[i]) + 1;
         nodeArray[i].new1 = (char *)malloc(len);
         memset(nodeArray[i].new1, 0 , len);
         nodeArray[i].old1 = strs[i];
         strcpy(nodeArray[i].new1, strs[i]);
         qsort(nodeArray[i].new1, len - 1, sizeof(char), cmp1);
     }
 }

 void arrayAllstr(Node *nodeArray, int strsSize) 
 {
     qsort(nodeArray, strsSize, sizeof(Node), cmp2);
 }

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    Node *nodeArray = (Node *)malloc(strsSize * sizeof(Node));
    arrayOneStr(strs, strsSize, nodeArray);
    arrayAllstr(nodeArray, strsSize);
    char ***res = (char ***)malloc(sizeof(char **) * strsSize);
    returnColumnSizes[0] = (int*)malloc(sizeof(int) * strsSize);
    char *tmp = nodeArray[0].new1;
    int len = strlen(tmp) + 1;
    int cnt = 0;
    res[cnt] = (char **)malloc(sizeof(char *) * 1000);
    int num = 0;
    
    for (int i = 0; i < strsSize; i++) {
        if (strcmp(tmp, nodeArray[i].new1) == 0) {
            res[cnt][num] = (char*)malloc(len);
            strcpy(res[cnt][num], nodeArray[i].old1);
            num++;
        }
        if (strcmp(tmp, nodeArray[i].new1) != 0) {
            returnColumnSizes[0][cnt] = num;
            len = strlen(nodeArray[i].new1) + 1;
            tmp = nodeArray[i].new1;
            num = 0;
            cnt++;
			res[cnt] = (char **)malloc(sizeof(char *) * 1000);
			i--;
        }
    }
    if (num != 0) {
        returnColumnSizes[0][cnt] = num;
        cnt++;
    }
    *returnSize = cnt;
    return res;
}
```