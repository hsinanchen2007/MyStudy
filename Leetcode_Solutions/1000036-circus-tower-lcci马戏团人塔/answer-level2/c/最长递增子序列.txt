![image.png](https://pic.leetcode-cn.com/23594cdf37e37eddbba2384c199955a3f4520b435f74116b21201bcbca464b92-image.png)

# 解法一：对身高升序排序，身高相同，按体重降序排序


1. 对身高升序排完序后，问题转换为求 体重的**最长递增子序列**长度 -> [最长递增子序列](https://blog.csdn.net/u013178472/article/details/54926531)
2. 身高相同时，体重需要是降序的状态


## 解法一：
```c
#define MAX_SIZE 10005

struct Person
{
    int weight;
    int height;
};

struct Person g_person[MAX_SIZE];
int arr[MAX_SIZE];

int Cmp(const void *a, const void *b)
{
    if (((struct Person *)a)->height != ((struct Person *)b)->height) {
        return ((struct Person *)a)->height - ((struct Person *)b)->height;
    } else {
        return ((struct Person *)b)->weight - ((struct Person *)a)->weight;
    }
}

int BinarySearch(int target, int left, int right)
{
    int mid;
    while(left < right){
        mid = (right + left) >> 1;
        if(arr[mid] >= target) {
            right = mid;
        }
        else {
            left = mid + 1;
        }            
    }
    return left;
}

int bestSeqAtIndex(int* height, int heightSize, int* weight, int weightSize) {
    if (height == NULL || weight == NULL || heightSize == 0 || weightSize == 0) {
        return 0;
    }

    int i;
    int tmp;
    for (i = 0; i < heightSize; ++i) {
        g_person[i].height = height[i];
        g_person[i].weight = weight[i];
    }
    qsort(g_person, heightSize, sizeof(struct Person), Cmp);
    arr[1] = g_person[0].weight;
    int index = 1;
    for(i = 1; i < heightSize; ++i) {
        if(g_person[i].weight > arr[index]) {
            ++index;
            arr[index] = g_person[i].weight;
        } else {
            tmp = BinarySearch(g_person[i].weight, 1, index);
            arr[tmp] = g_person[i].weight;
        }
    }

    return index;
}
```
