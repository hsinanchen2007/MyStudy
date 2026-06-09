### 解题思路
HASH建表，内容是排序后得字符串，并记录每个字符串的位置，最后输出
### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
typedef struct My_Hash_Node {
    char str[1000];
    int val[1000];
    int refernce;
    UT_hash_handle hh;
}MY_HASH_NODE_S;

MY_HASH_NODE_S * g_Nodes = NULL;

int Compare(char* a, char* b) 
{
    return *a - *b;
}

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    char tmpArr[1000] = {0};
    MY_HASH_NODE_S *node = NULL;
    MY_HASH_NODE_S *cur = NULL;
    int tmpLen = 0;
    char *** retGroup = NULL;
    *returnSize = 0;
    if(strs == NULL || strsSize == 0) {
        return NULL;
    }

    // 建立查找HASH表，将满足条件的字符串下标记录下来
    for (int i = 0; i < strsSize; i++) {
        if (strs[i] != NULL) {
            tmpLen = strlen(strs[i]);
            strncpy(tmpArr, strs[i], tmpLen);
            qsort(tmpArr, tmpLen, sizeof(char), Compare);
            
            HASH_FIND_STR(g_Nodes, tmpArr, node);
            if (!node) {
                node = (MY_HASH_NODE_S*)malloc(sizeof(MY_HASH_NODE_S));
                node->refernce = 1;
                node->val[0] = i;
                strncpy(node->str, tmpArr, tmpLen);
                node->str[tmpLen] = '\0';
                HASH_ADD_STR(g_Nodes, str, node);
                (*returnSize) ++;
                //printf("create hash %s, ret %d\r\n",node->str,*returnSize);
            } else {
                 //printf("same hash %s, tmp %s\r\n",node->str,tmpArr);
                node->val[node->refernce] = i;
                node->refernce++;
            }
        }
        memset(tmpArr, 0, 1000);
    }
    // 遍历HASH，按照要求返回字符串数组
    retGroup = (char ***)malloc(sizeof(char **)*strsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    node = NULL;
    int i = 0;
    int len = 0;
    HASH_ITER(hh, g_Nodes, cur, node) {
        //printf("find hash %s, ref %d\r\n",cur->str, cur->refernce);
        retGroup[i] = (char **)malloc(sizeof(char *) * cur->refernce);
        len = strlen(cur->str);
        (*returnColumnSizes)[i] = cur->refernce;
        for (int j = 0; j < cur->refernce; j++) {
            retGroup[i][j] = (char*)malloc(sizeof(char) * (len+1));
            strncpy(retGroup[i][j], strs[cur->val[j]], len);
            retGroup[i][j][len] = '\0';
           // printf("create arr %s, retarr %s, index %d\r\n",strs[cur->val[j]], retGroup[i][j],len);
        }
        i++;
        HASH_DEL(g_Nodes,cur);
        free(cur);
    }
    //printf("return size %d closi %d\r\n",*returnSize,*returnColumnSizes[0]);
    return retGroup;
}
```