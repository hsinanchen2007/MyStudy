### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 /* 该结构体用于存放当前节点的字符 */
 typedef struct {
     struct TreeNode treenode;
     char ch[100];
 } CharTreeNode;

 typedef struct {
     int front;
     int rear;
     int size;
     CharTreeNode data[1000];
 }Quene;


 char intochar(int a) {
     char ret;
     switch (a) {
         case 0: ret = '0'; break;
         case 1: ret = '1'; break;
         case 2: ret = '2'; break;
         case 3: ret = '3'; break;
         case 4: ret = '4'; break;
         case 5: ret = '5'; break;
         case 6: ret = '6'; break;
         case 7: ret = '7'; break;
         case 8: ret = '8'; break;
         case 9: ret = '9'; break;
         default: ret = '0';break;
     }
     return ret;
 }

 char* inttoStr(int a) {
     int temp = 0;
     int cnt = 0;
     if(a < 0) {
         cnt = 1;
     }
    temp = abs(a);
     /*获取A的位数*/
     while (temp > 0) {
         cnt++;
         temp = temp / 10;
     }
     temp = abs(a);
     char* str = (char*)malloc(sizeof(char) * cnt);
     for(int i = cnt-1; i >= 0; i--) {
        if(i == 0 && a < 0) {
            str[i] = '-';
        } else {
            str[i] = intochar(temp % 10);
            temp = temp / 10;
        }
     }
     return str;
 }
 void Init(Quene* q) {
     q->front = -1;
     q->rear = -1;
     q->size = 0;
     memset(q->data, 0, sizeof(CharTreeNode) * 1000);
 }

 int pop(Quene* q, CharTreeNode** data) {
     if(q == NULL || q->size < 0) {
         return -1;
     }
     *data = &(q->data[q->front]);
     q->front++;
     q->front = q->front % 1000;
     q->size = q->size - 1;
     return 0;
 }
 int push(Quene* q, CharTreeNode* data) {
     if(q == NULL || q->size > 1000) {
         return -1;
     }
     if(q->front < 0) {
         q->front = 0;
     }
     q->rear++;
     q->rear = q->rear % 1000;
     q->data[q->rear] = *data;
     q->size = q->size + 1;
     return 0;
 }
/* 如果不是根节点，则继承父节点的字符，如果是根节点，则将父节点字符打出来 */
char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    char** retCol = (char**)malloc(sizeof(char*) * 1000);
    int cnt = 0;
    Quene  q;
    Init(&q);
    CharTreeNode treeroot;
    memset(&treeroot, 0, sizeof(CharTreeNode));
    treeroot.treenode = *root;
    strcat(treeroot.ch, inttoStr(root->val));
    //printf("treeroot.ch[0] is %s\n",treeroot.ch);
    push(&q, &treeroot);
    CharTreeNode* data;
    CharTreeNode dataTemp;
    while(q.size != 0) {
        int cur_size = q.size;
        //printf("cur_size is %d\n",cur_size);
        while(cur_size--) {
            pop(&q, &data);
            //printf("data->ch is %s\n",data->ch);
            /* 如果没有子节点，则申请内存保存字符*/
            if (data->treenode.left == NULL && data->treenode.right == NULL) {
                //printf("left and right is  NULL cnt is %d,strlen(data->ch) is %d\n", cnt, strlen(data->ch));
                retCol[cnt] = (char*)malloc(sizeof(char) * 100);
                memset(retCol[cnt], 0, 100);
                //strcat(&retCol[cnt], &(data->ch));
                memcpy(retCol[cnt], data->ch, sizeof(char) * strlen(data->ch));
                cnt++;
            }
            /*如果左子节点不为空，压入队列，更新val*/
            if(data->treenode.left) {
                //printf("left is not NULL\n");
                memset(&dataTemp, 0, sizeof(CharTreeNode));
                dataTemp.treenode = *(data->treenode.left);
                memcpy(&(dataTemp.ch), data->ch, sizeof(char) * 100);
                char chtemp[50] = {0};
                chtemp[0] = '-';
                chtemp[1] = '>';
                strcat(chtemp,inttoStr(dataTemp.treenode.val));
                //chtemp[2] = intochar(dataTemp.treenode.val);
                strcat(&(dataTemp.ch), chtemp);
                //printf("dataTemp.ch is %s\n",dataTemp.ch);
                push(&q, &dataTemp);
            }
            /*如果右子节点不为空，压入队列，更新val*/
            if(data->treenode.right) {
                //printf("right is not NULL\n");
                memset(&dataTemp, 0, sizeof(CharTreeNode));
                dataTemp.treenode = *(data->treenode.right);
                memcpy(dataTemp.ch, data->ch, sizeof(char) * 100);
                char chtemp[50] = {0};
                chtemp[0] = '-';
                chtemp[1] = '>';
                strcat(chtemp,inttoStr(dataTemp.treenode.val));
                //chtemp[2] = intochar(dataTemp.treenode.val);
                strcat(dataTemp.ch, chtemp);
                //printf("dataTemp.ch is strlen:%d\n",strlen(dataTemp.ch));
                //printf("dataTemp.ch is %s\n",dataTemp.ch);
                push(&q, &dataTemp);
            }
        }
    }
    *returnSize = cnt;
    return retCol;
}
```