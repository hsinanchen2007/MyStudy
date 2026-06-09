一开始用的常规方法超时，参考评论区大神的解法，先排序，后遍历

```
#define myAbs(x)    ((x) > 0 ? (x) : (-x))

typedef struct node 
{
    int data;
    int index;
}myNode;

int comp(const void *a,const void *b)
{
    return ((*(myNode*)a).data < (*(myNode *)b).data) ? -1 : 1;
}

bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    if(numsSize < 2 || nums == NULL)
    {
        return false;
    }

    myNode* numdata;
    numdata = (myNode*)malloc(sizeof(myNode) * numsSize);
    if(numdata == NULL)
    {
        return false;
    }

    for(int i = 0 ; i < numsSize ; i++)
    {
        numdata[i].data = nums[i];
        numdata[i].index = i;
    }

    qsort(numdata , numsSize , sizeof(myNode) , comp);

    int cmpIndex = 0;
    myNode cmpNode = numdata[cmpIndex];
    for(cmpIndex = 1 ; cmpIndex < numsSize ; cmpIndex++)
    {
        if(cmpNode.data == numdata[cmpIndex].data)
        {
            if(myAbs(cmpNode.index - numdata[cmpIndex].index) <= k)
            {
                return true;
            }
        }
        cmpNode = numdata[cmpIndex];
    }
    return false;
}
```
![1.png](https://pic.leetcode-cn.com/1ee447a4540d15f63f2016cced3eae14387e8a15584662cb6b72756640b7ad31-1.png)

内存占用太多- -、、

