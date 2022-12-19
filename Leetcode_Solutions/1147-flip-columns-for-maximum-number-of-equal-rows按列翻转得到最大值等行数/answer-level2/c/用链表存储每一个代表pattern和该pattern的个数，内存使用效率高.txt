### 解题思路
此处撰写解题思路

### 代码

```c
typedef struct pattern
{
    int *row;
    int length;
    struct pattern *next;
}pattern;
bool compare(int *a,int *b,int size){
    int i;
    for(i=0;i<size;i++){
        if(a[i]!=b[i]){
            break;
        }
    }
    if(i==0){
        for(i=0;i<size;i++){
            if(a[i]==b[i]){
                break;
            }
        }
    }
    if(i==size)
       return true;
    else
       return false;
}
int maxEqualRowsAfterFlips(int** matrix, int matrixSize, int* matrixColSize){
    int i,max_length=1;
    struct pattern *head=NULL,*p,*q;
    head=(struct pattern*)malloc(sizeof(struct pattern));
    head->row=matrix[0];
    head->length=1;
    head->next=NULL;
    printf("%d,%d",matrixSize,*matrixColSize);
    for(i=1;i<matrixSize;i++){
        for(p=head;p!=NULL;q=p,p=p->next){
            if(compare(matrix[i],p->row,*matrixColSize)){
                p->length++;
                if(p->length>max_length){
                    max_length=p->length;
                }
                break;
            }
        }
        if(p==NULL){
            p=(struct pattern*)malloc(sizeof(struct pattern));
            q->next=p;
            p->row=matrix[i];
            p->length=1;
            p->next=NULL;

        }
    }
    return max_length;
}
```
