```C 

/*事实上，诸如此类的，要在一个数组中寻找第K大的数（或者第K小的数），前K大的数，前K小的数，一般来说的方法有：1.先排序（快排）时间复杂度为nlogn
2.建堆，堆的数量为K，建立大根堆或者小根堆，时间复杂度为Klogn(如果要求出前K个较大的，那么就建立小根堆，一旦比堆顶大，那么就入堆)；3.结合快速排序划分的方法，不断减小问题的规模*/

/*方法1：最简单的算出各个点到原点的距离然后再排序；*/
/*二维数组的元素是一位数组*/

/*int compare(const void *p,const void *q)    const void 应该要转为指向数组元素的指针，数组的元素是一维数组，所以应该转为指向一维数组的指针，
也就是说需要转为二级指针
{
    int **s=(int **)p;
    int **t=(int **)q;
    return (*s)[0]*(*s)[0]+(*s)[1]*(*s)[1]-(*t)[0]*(*t)[0]-(*t)[1]*(*t)[1];
}
int** kClosest(int** points, int pointsSize, int* pointsColSize, int K, int* returnSize, int** returnColumnSizes){
    int **result=(int **)malloc(sizeof(int *)*K);
    *returnSize=K;
    *returnColumnSizes=(int *)malloc(sizeof(int)*K); 
    qsort(points,pointsSize,sizeof(int)*2,compare);     二维数组的元素是一维数组，所以元素的长度为2*sizeof(int)
    for(int i=0;i<K;i++)
    {
        result[i]=(int *)malloc(sizeof(int)*2);
        result[i][0]=points[i][0];
        result[i][1]=points[i][1];
        (*returnColumnSizes)[i]=2;
    }
    return result;
}
*/
/*方法2：堆排序法*/
/*typedef struct node{
    int row;
    int column;
    int dist;
}Node_t,*pNode_t;
void adjustheap(pNode_t heap,int start,int end)
{
    Node_t temp;
    int dad=start;
    int son=dad*2+1;
    while(son<end)
    {
        if(son+1<end&&heap[son+1].dist>heap[son].dist)
            son++;
        if(heap[dad].dist>heap[son].dist)
            return;
        else
        {
            temp=heap[dad];
            heap[dad]=heap[son];
            heap[son]=temp;
            dad=son;
            son=dad*2+1;
        }
    }
}

int** kClosest(int** points, int pointsSize, int* pointsColSize, int K, int* returnSize, int** returnColumnSizes){
    pNode_t heap=(pNode_t)malloc(sizeof(Node_t)*pointsSize);
    int i,k;
    for(i=0;i<pointsSize;i++)
    {
        heap[i].row=points[i][0];
        heap[i].column=points[i][1];
        heap[i].dist=heap[i].row*heap[i].row+heap[i].column*heap[i].column;
    }
    for(i=K/2-1;i>=0;i--)
        adjustheap(heap,i,K);
    k=K;
    while(k<pointsSize)
    {
        if(heap[k].dist<heap[0].dist)
        {
            heap[0]=heap[k];
            adjustheap(heap,0,K);
        }
        k++;
    }
    int **result=(int **)malloc(sizeof(int *)*K);
    *returnSize=K;
    *returnColumnSizes=(int *)malloc(sizeof(int)*K); 
    for(int i=0;i<K;i++)
    {
        result[i]=(int *)malloc(sizeof(int)*2);
        result[i][0]=heap[i].row;
        result[i][1]=heap[i].column;
        (*returnColumnSizes)[i]=2;
    }
    return result;
}*/
/*方法3：*/

typedef struct node{
    int row;
    int column;
    int dist;
}Node_t,*pNode_t;
void Partionandfind(pNode_t Node, int start, int end, int seq) {
	int k = end;
	Node_t temp;
	for (int i = end; i >= start; i--)
	{
		if (Node[start].dist<Node[i].dist)
		{
			temp = Node[k];
			Node[k] = Node[i];
			Node[i] = temp;
			k--;
		}
	}
	temp = Node[start];
	Node[start] = Node[k];
	Node[k] = temp;
	if (k - start == seq - 1)
		return;
	else if (k - start>seq - 1)
		Partionandfind(Node, start, k - 1, seq);
	else
		Partionandfind(Node, k + 1, end, seq - (k - start) - 1);
}
int** kClosest(int** points, int pointsSize, int* pointsColSize, int K, int* returnSize, int** returnColumnSizes) {
	pNode_t heap = (pNode_t)malloc(sizeof(Node_t)*pointsSize);
	int i, k;
	for (i = 0; i<pointsSize; i++)
	{
		heap[i].row = points[i][0];
		heap[i].column = points[i][1];
		heap[i].dist = heap[i].row*heap[i].row + heap[i].column*heap[i].column;
	}
	Partionandfind(heap, 0, pointsSize - 1, K);
	int **result = (int **)malloc(sizeof(int *)*K);
	*returnSize = K;
	*returnColumnSizes = (int *)malloc(sizeof(int)*K);
	for (int i = 0; i<K; i++)
	{
		result[i] = (int *)malloc(sizeof(int) * 2);
		result[i][0] = heap[i].row;
		result[i][1] = heap[i].column;
		(*returnColumnSizes)[i] = 2;
	}
	return result;
}
```

