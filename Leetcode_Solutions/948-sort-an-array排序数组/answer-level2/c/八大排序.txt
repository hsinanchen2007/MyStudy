### 解题思路
此处撰写解题思路

### 代码

```c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 // 插入排序   超出时间限制
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int end = i;
		int next = a[end + 1];//保存下一个数的值，避免被覆盖
		while (end >= 0 && a[end]>next)//对前面排好序的一部分从后往前在比较，有大的就往后覆盖，下一个还大就覆盖，直到没有大与 要插入的这个next，跳出循环，
		{
			a[end+1] = a[end];
			end--;
		}
		a[end + 1] = next; //再在终止的位置把要插入的next赋值进去
	}
}
//希尔排序   可以通过
void ShellSort(int *a,int n)
{
    int gap=n;
    while(gap>1)
    {
        gap=gap/3+1;
        for(int i=0;i<n-gap;i++)
        {
            int end=i;
            int next=a[end+gap];
            while(end>=0 && a[end]>next)
            {
                a[end+gap]=a[end];
                end-=gap;
            }
            a[end+gap]=next;
        }
    }
}
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
// 选择排序  超出时间限制
void SelectSort(int* a, int n)
{
    int begin=0;
    int end=n-1;
    while(begin<end)
    {
        int min=begin;
        int max=end;
        for(int i=begin;i<=end;i++)
        {
            if(a[max]<=a[i])
            {
                max=i;
            }
            if(a[min]>a[i])
            {
                min=i;
            }
        }
        swap(&a[begin],&a[min]);
        if(begin==max)
        {
            max=min;
        }
        swap(&a[end],&a[max]);
        begin++;
        end--;
    }
}
//堆排序     可以提交
void justdown(int *a,int n,int root)//向下调整算法
{
    int parent=root;
    int child=parent*2+1;
    while(child<n)
    {
        if((child+1)<n && a[child+1]>a[child])
        {
            child++;
        }
        if(a[child]>a[parent])
        {
            swap(&a[child],&a[parent]);
            parent=child;
            child=parent*2+1;
        }
        else
        {
            break;
        }
    }
}
void HeapSort(int *a,int n)//堆排
{
    for(int i=(n-2)/2;i>=0;i--)
    {
        justdown(a,n,i);
    }
    int end=n-1;
    while(end>0)
    {
        swap(&a[0],&a[end]);//把堆顶的最大的数放出去，小的数换进去继续调整
        justdown(a,end,0);
        end--;
    }
}
// 冒泡排序   超时
void BubbleSort(int* a, int n)
{
    int end=n-1;
    while(end>0)
    {
        int flag=0;
        for(int i=1;i<=end;i++)
        {
            if(a[i-1]>a[i])
            {
                swap(&a[i-1],&a[i]);
                flag=1;
            }
        }
        if(flag==0)
        {
            break;
        }
        end--;
    }
}
//三数曲中优化找基准值
//1.三数区中法   最左边  中间   最右边三个数中的中位数的下标
//先找出数组中三者之间中间数的下标 作为快排的基准值
int Gitmidindex(int *a,int begin,int end)
{
	int mid=(begin+end)/2;
	if(a[begin]<a[mid])
	{
		if(a[end]>a[mid])
		{
			return mid;
		}
		else if(a[begin]>a[end])
		{
			return begin;
		}
		else
			return end;
	}
	else //a[begin]>a[mid]
	{
		if(a[mid]>a[end])
		{
			return mid; 
		}
		else if(a[end]>a[begin])
		{
			return begin;
		}
		else
			return end;
	
	}
}

int partsort(int *a,int begin,int end)
{
    int mid=Gitmidindex(a,begin,end);
    swap(&a[begin],&a[mid]);
    int key=a[begin];//保存基准值
    int start=begin;
    while(begin<end)
    {
        while(begin<end && a[end]>=key)
        {
            end--;
        }
        while(begin <end && a[begin]<=key)
        {
            begin++;
        }
        swap(&a[begin],&a[end]);
    }
    swap(&a[start],&a[begin]);
    return begin;
}
//2.挖坑优化
int partsort2(int *a,int begin,int end)
{
    int key=a[begin];//把自己变成坑
    while(begin<end)
    {
        while(begin<end && a[end]>=key)
        {
            end--;
        }
        a[begin]=a[end];
        while(begin<end && a[begin<=key])
        {
            begin++;
        }
        a[end]=a[begin];
    }
    a[begin]=key;
    return begin;
    
}
//3.前后指针法
int partsort3(int *a,int begin,int end)
{
    int key=a[begin];
    int prev=begin;
    int cur=begin+1;
    while(cur<=end)
    {
        if(a[cur]<key)
        {
            prev++;
            swap(&a[prev],&a[cur]);
            cur++;
        }
        else
            cur++;
    }
    swap(&a[prev],&a[begin]);
    return prev;
}
void QuickSort(int *a,int begin,int end)
{
    if(begin<end)
    {
        if(end-begin+1<10)//小区间优化，数据个数小于一定值，就可以用插入来处理小数据
        {
            InsertSort(a+begin,end-begin+1);
        }
        else
        {
            int keymid=partsort3(a,begin,end);
            QuickSort(a,begin,keymid-1);
            QuickSort(a,keymid+1,end);
        }
        
    }
}
//归并排序 先划分在合并
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left >= right)  //一直分到每组只剩一个元素就停止划分，准备开始归并
	{
		return;
	}
	int mid = left + ((right - left) >> 1);
	_MergeSort(a, left, mid, tmp);     //先递归划分，再出栈合并
	_MergeSort(a, mid + 1, right, tmp);
	// [left, mid]
	// [mid+1, right]
	int i = left, j = mid;
	int x = mid + 1, z = right;
	int k = left;
	
	//将有二个有序数列a[left...mid]和a[mid...right]合并。
	while (i <= j && x<=z)
	{
		if (a[i] <=a[x])
		{
			tmp[k++] = a[i++];
		}
		else
		{
			tmp[k++] = a[x++];
		}
	}
	while(i <= j)
		tmp[k++] = a[i++];
	while(x <= z)
		tmp[k++] = a[x++];
	memcpy(a + left, tmp + left, sizeof(int)*(right - left+1 ));
}
void MergeSort(int* a, int n)
{
	int* tmp = (int *)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}
//计数排序
void CountSort(int* a,int n)
{
    //先找出区间大小
    int i=0;
    int min=a[0];
    int max=a[0];
    for(i=0;i<n;i++)
    {
        if(a[i]<min)
            min=a[i];
        if(a[i]>max)
            max=a[i];
    }
    //开空间，计数
    int range=max-min+1;
    int *tmp=(int*)calloc(range,sizeof(int));
    for(i=0;i<n;i++)
    {
        int x=a[i]-min;
        tmp[x]++;
    }
    //把计下来的数取出来
    int k=0;
    for(i=0;i<range;i++)
    {
        while(tmp[i]--)
        {
            a[k++]=i+min;
        }
    }
    free(tmp);

}
int* sortArray(int* nums, int numsSize, int* returnSize){
    CountSort(nums,numsSize);
    *returnSize=numsSize;
    return nums;

}
```