### 解题思路
此处撰写解题思路
用球根公式暴力找根，结果遇到很大的数据就overflow了
还有就是int** returnColumnSizes这个参数是真的搞不懂到底什么意思
### 代码

```c
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
 /*
 //n^2+(2*i-1)*n-2*target=0   n=(1-2i+x)/2 其中x^2=(1-2i)^2+8*target
int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    long long int sq,x,sqx;
    int n;
    bool flag=false;
    int cnt=0;
    *returnSize=0;
    typedef struct L_NODE{ //因为不知道会有多少结果所以用链表存找到的i和n
        int a0;
        int n;
        struct L_NODE *next;
    }LNode;
    LNode *head=NULL,*tail=NULL;
    for(int i=1;i<=target/2;i++)
    {
       // printf("i:%d ",i);
        sq=(2*i-1)*(2*i-1)+8*target;
        x=i>2?(2*i-1):3;
        sqx=x*x;
        while(sqx<=sq)
        {
            //printf("sqx=%d sq=%d ",sqx,sq);
            if(sqx==sq)
            {
                n=(1-2*i+x)/2;
                flag=true;
                break;
            }
            x+=2;
            sqx=x*x;
        }
        if(flag)
        {
            //printf("%d %d\n",i,n);
            LNode *newnode;
            newnode=(LNode *)malloc(sizeof(LNode));
            newnode->a0=i;
            newnode->n=n;
            newnode->next=NULL;
            if(head==NULL)
            {
                head=tail=newnode;
            }
            else
            {
                tail->next=newnode;
                tail=newnode;
            }
            cnt+=1;
            *returnSize+=n;
            flag=false;
        }
    }
    printf("\nrs=%d\n",*returnSize);

    int **ans;
    ans=(int **)malloc((cnt)*sizeof(int*));
    int cur_a0,cur_n;
    LNode *tmp;
    int *p;
    p=(int *)malloc((cnt)*sizeof(int));
    *returnColumnSizes=p;
    for(int i=0;i<cnt;i++)
    {
        //取出a0和n
        cur_a0=head->a0;
        cur_n=head->n;
        tmp=head;
        head=head->next;
        free(tmp);
        //分配ans[i][]的空间
        *(ans+i)=(int *)malloc(cur_n*sizeof(int));
       // ans[i]=(int *)malloc(cur_n*sizeof(int)); //效果一样
       // *((*returnColumnSizes)+i)=cur_n;
        (*returnColumnSizes)[i]=cur_n;
        printf("a0=%d n=%d ",cur_a0,cur_n);
        for(int j=0;j<cur_n;j++)
        {
            ans[i][j]=j+cur_a0;
            printf("%d ",ans[i][j]);
        }
    }
    *returnSize=cnt;
    for(int i=0;i<cnt;i++)
    {
        printf("\nrcs=%d\n",(*returnColumnSizes)[i]);
        for(int j=0;j<(*returnColumnSizes)[i];j++)
        {
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
    return ans;
}
*/

int** findContinuousSequence(int target, int* returnSize, int** returnColumnSizes){
    int n = target / 2;
    int **res = (int**)malloc(sizeof(int*) * n);
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    *returnSize = 0;
    int l = 1;
    int r = 2;
    int sum = l + r;
    int k;
    while (l < r) {
        if (sum == target) { /* 结果输出 */
            res[*returnSize] = (int*)malloc(sizeof(int) * (r - l + 1));
            for (k = l; k <= r; k++) {
                res[*returnSize][k - l] = k;
                (*returnColumnSizes)[*returnSize] = r - l + 1;
            }
            (*returnSize)++;
            sum -= l;
            l++;
        } else if (sum < target) {
            r++;
            sum += r;
        } else {
            sum -= l;
            l++;
        }
    }
    return res;
}
```