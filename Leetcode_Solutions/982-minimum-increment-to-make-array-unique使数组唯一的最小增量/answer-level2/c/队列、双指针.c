### 解题思路
1、将数组排序
2、设计一个队列
3、双指针遍历数组
4、若A[i]==A[j]表明有重复元素，将重复元素入队
5、若A[j]-A[i]>0,表明两者之间有空闲地盘，出队，将之前的重复元素填入
6、遍历完数组之后，将队列内剩余元素通通放到最大元素之后

### 代码

```c
int cmp(const void *a,const void *b){
    if(*(int *)a>0&&*(int *)b<0)
        return 1;
    if(*(int *)a<0&&*(int *)b>0)
        return -1;
    return *(int *)a-*(int *)b;
}

int minIncrementForUnique(int* A, int ASize){
    if(ASize==1||ASize==0)
        return 0;

    qsort(A,ASize,sizeof(int),cmp);
    
    int i=0,j=1,result=0;
    int *temp=(int *)malloc(sizeof(int)*ASize);
    int rear=0,front=0;
    int x=0;
    while(j<ASize){
        int gap=A[j]-A[i];
        switch(gap){
            case 0:         //元素重复，入队
                temp[rear++]=A[j++];
                break;            
            default:        //有多余空位，填入之前重复的元素
                x=1;
                while(gap-1>=x&&front!=rear){
                    result=result+x+A[i]-temp[front++];
                    x++;
                }
                i=j++;
        }

    }
        x=1;        //遍历结束之后，将对内还有的元素，填入数组之后
        while(front!=rear){
            result=result+x+A[ASize-1]-temp[front++];
            x++;
        }
        return result;
}
```