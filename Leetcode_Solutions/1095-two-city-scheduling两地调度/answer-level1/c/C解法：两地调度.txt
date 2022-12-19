### 解题思路
最好情况时，时间复杂度O(nlogn)

第i个人去A地减去去B第的差值dif=costs[i][0]-costs[i][0]
计算出每一个人的dif，并将dif和每个人在costs的坐标i记录在Node中，
然后用快速排序对Node中的dif按照从小到大排序。让前一半的人去A地，后一半人去B地。
最后按照题意计算总费用。

至于为什么这样能得到最优解可以参照题解（记得有大佬证明了）
如果想要优化可以换其他排序试一下。

### 代码

```c
//dif用于记录第i个人去A地减去去B第的差值
//position用于记录在costs的坐标
struct Node
{
    int dif;
    int position;
};
//int cal_mid(struct Node*lst,int left,int right)
//void sort(struct Node*lst,int left,int right)
//struct Node*QuickSort(struct Node*lst,int costsSize)
//以上注释中的函数都跟快速排序有关，可略去不看



int cal_mid(struct Node*lst,int left,int right)
{

    struct Node temp=lst[left];
    while(left<right)
    {
        while(left<right&&lst[right].dif>temp.dif)right--;
        lst[left]=lst[right];
        while(left<right&&lst[left].dif<=temp.dif)left++;
        lst[right]=lst[left];
    }
    lst[left]=temp;
    return left;
}

//快速排序递归过程
void sort(struct Node*lst,int left,int right)
{
    if(left<right)
    {
        int mid=cal_mid(lst,left,right);
        sort(lst,left,mid-1);
        sort(lst,mid+1,right);
    }

}
//快速排序函数主体
struct Node*QuickSort(struct Node*lst,int costsSize)
{
    sort(lst,0,costsSize);
    return lst;
}

//主调函数
int twoCitySchedCost(int** costs, int costsSize, int* costsColSize){
    struct Node* lst=(struct Node*)malloc(sizeof(struct Node)*costsSize);
    //lst_pos用于记录在lst中访问到哪的坐标
    int lst_pos=0;
    //计算差值dif，并将其和在costs的坐标记录在结构体中
    for(int i=0;i<costsSize;i++)
    {
        int dif=*(*(costs+i))- *(*(costs+i)+1);
        (lst+lst_pos)->dif=dif;
        (lst+lst_pos)->position=i;
        lst_pos++;
    }
    //调用快速排序
    lst=QuickSort(lst,costsSize-1);

    //可以用来看看快速排序的结果
    // for(int i=0;i<costsSize;i++)
    // {
    //     printf("lst[%d]->dif:%d\n",i,lst[i].dif);
    // }
   
    //计算总和sum
    int sum=0;
    int count=0;
    //len记录一半人的个数
    int len=costsSize/2;
    for(int i=0;i<costsSize;i++)
    {
        int cos_pos=lst[i].position;
        if(count<len) 
        {
            //如果看着不舒服可以换成lst[m][n]
            sum+=*(*(costs+cos_pos));
            count++;
        }
        else
        {
            sum+=*(*(costs+cos_pos)+1);
        }
    }
    return sum;
}
```