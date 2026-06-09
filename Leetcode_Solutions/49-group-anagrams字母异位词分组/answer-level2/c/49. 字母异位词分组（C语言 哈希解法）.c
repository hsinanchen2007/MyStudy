### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/eba2c5289386a8974de50013c8e5f476971cacba7b60e8172bb5ffb91a1d5799-image.png)
该题关键是如何构建哈希计算公式，要保证不同顺序的单词得到的结果相同，字母有差异时，得到的结果不同。
考虑用unsigned long long数据类型，一共占64位，而字母都是小写的，所以把字母尽量平均到不同位上，互相之间还得有差别。
考虑把字符左移 （ch - 'a')*2位，来平均分配到不同位上；

公式如下：
return (unsigned long long )(ch - 'a' + 1)<<((ch - 'a') * 2);
不过有点碰运气的成分。
### 代码

```c
#define DEBUG 0
unsigned long long GetLetterValue(char ch)
{
    return (unsigned long long )(ch - 'a' + 1)<<((ch - 'a') * 2);
}
typedef struct _node_t {
    char *str;
    struct _node_t *next;
}node_t;
typedef struct _head_t {
    unsigned long long sum;
    int num;
    node_t * node;
    struct _head_t *next;
}head_t;
head_t *CreatHead(node_t *node, unsigned long long sum)
{
    head_t *head = (head_t *)malloc(sizeof(head_t));
    head->sum = sum;
    head->num = 1;
    head->next = NULL;
    head->node = (node_t *)malloc(sizeof(node_t));
    head->node->next = node;
    head->node->str = NULL;
    return head;
}
node_t *CreatNode(char *str)
{
    node_t *node = (node_t *)malloc(sizeof(node_t));
    node->str = str;
    node->next = NULL;
    return node;
}
void AddStrNode(head_t *head, char *str)
{
    unsigned long long sum = 0;
    for (char *p_str = str; *p_str != '\0'; p_str++) {
        sum += GetLetterValue(*p_str);
    }
    node_t *p_node = CreatNode(str);

    if (head->next == NULL) {
        head->next = CreatHead(p_node,sum);
        head->num = 1;
        return;
    }
    head_t *p_head = head;
    while (p_head->next != NULL) {
        p_head = p_head->next;
        if (p_head->sum == sum) {
            p_node->next = p_head->node->next;
            p_head->node->next = p_node;
            p_head->num++;
            return;
        }
    }
    p_head->next = CreatHead(p_node,sum);
    head->num++;
}
void PrintNode(node_t *node)
{
    if (node == NULL) return;
    if (node->str != NULL) {
        printf("\"%s\"",node->str);
        if (node->next != NULL) {
            printf(",");
        }
    }
    PrintNode(node->next);
}
void PrintHead(head_t *head)
{
    if (DEBUG != 1 || head == NULL) return;
    PrintNode(head->node);
    printf("\n");
    PrintHead(head->next);
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    if (strs == NULL || strsSize < 1 || returnSize == NULL || returnColumnSizes == NULL) return NULL;
    head_t *head = CreatHead(NULL, 0);
    head->num = 0;
    for (int i=0; i<strsSize; i++) {
        AddStrNode(head,strs[i]);
    }
    PrintHead(head);
    head_t *p_head = head->next;
    node_t *p_node = NULL;
    if(DEBUG) printf("%d",head->num);
    *returnSize = 0;
    char ***ret = (char ***)malloc(sizeof(char ***) * (head->num));
    *returnColumnSizes = (int *)malloc(sizeof(int) * (head->num));
    
    int i=0, j=0;
    while (p_head != NULL && p_head->node != NULL) {
        p_node = p_head->node->next;
        i = (*returnSize);
        (*returnColumnSizes)[i] = 0;
        ret[i] = (char **)malloc(sizeof(char **) * (p_head->num +10));
        while (p_node != NULL && p_node->str != NULL) {
            j = (*returnColumnSizes)[i];
            ret[i][j] = p_node->str;
            p_node = p_node->next;
            (*returnColumnSizes)[i]++;
        }
        p_head = p_head->next;
        (*returnSize)++;
    }
     return ret;
}

/* test case
["eat","tea","tan","ate","nat","bat"]

["a","aa","aaa"]
["z","z","zz","zz","az","za","zzza","azzz","zazzz","azaaa"]

*/


```