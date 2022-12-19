### 解题思路
窗口法
用链表+数组的方式可以节省内存

### 代码

```c


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 typedef struct Node
 {
     int nums;
     int *data;
     struct Node *next;
 }node;

void insert(node* Head,int *Data,int Size)
{
    Head->nums=Head->nums+1;
    while(Head->next!=0)Head=Head->next;
    node* newNode=(node*)malloc(sizeof(node));
    newNode->nums=Size;
    newNode->data=Data;
    newNode->next=Head->next;
    Head->next=newNode;
}

int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    //先建立一个链表存放数据
    node *head=(node *)malloc(sizeof(node));
    head->next=0;
    head->nums=0;
    //用窗口法查找符合条件的数据
    int low=1,window=2,high=3;
    while(high<target)
    {
        int sum=0;
        for(int i=0;i<window;++i)
            sum+=(low+i);
        if(sum<target)
        {
            window++;
            high++;
        }
        else if(sum>target)
        {
            window--;
            low++;
        }
        else if(sum==target)
        {
            int *temp=(int *)malloc(sizeof(int)*window);
            for(int i=0;i<window;++i)
                temp[i]=low+i;
            insert(head,temp,window);
            window--;
            low++;
        }
    }
    //从链表中导出数据
    *returnSize=head->nums;
    *returnColumnSizes=(int*)malloc(sizeof(int)**returnSize);
    int** result=(int**)malloc(sizeof(int*)*(head->nums));

    for(int row=0;head->next!=0;++row)
    {
        result[row]=head->next->data;
        (*returnColumnSizes)[row]=head->next->nums;

        node *del=head->next;
        head->next=del->next;
        free(del);
    }

    return result;
}


```