### 解题思路
题中有numsize/2的元素是相同的，为了节省空间，我们可以选择只给它numsize/2+1个大小的数组，在一个数组里存放数字，在另一个数组里存放出现的次数。

插入时：先用绝对值（因为有负数元素）对哈希表的大小取余数，其他步骤都是常规操作 。

查找时：找到一个次数大于numsize/2的元素，返回即可。

时间复杂度:因为只需要遍历一次数组和一次哈希表,所以时间复杂度是O(n)。

### 代码

```c
typedef struct node{
    int *a;
    int *b;
    int table;
}Hash;

Hash* build(int n)
{
    Hash* h = (Hash*)malloc(sizeof(Hash));
    h->a = (int*)malloc(sizeof(int)*n);
    h->b = (int*)malloc(sizeof(int)*n);
    h->table = n;
    for(int i=0; i<n; i++){
        h->b[i] = 0;
        h->a[i] = -999;
        }
    return h;
}

void insert(Hash* h,int x)
{
    int index = abs(x%h->table);
    while(h->b[index]!=0){
        if(h->a[index] == x){
            h->b[index]++;
            return ;
        }
        else{
            index = (index+1)%h->table;
        }
    }
    h->a[index] = x;
    h->b[index]++;   
}

int majorityElement(int* nums, int numsSize){
    int max;
    Hash* h = build(numsSize/2+1);
    for(int i=0;i<numsSize;i++)
        insert(h,nums[i]);
    for(int i=0;i<h->table;i++)
        if(h->b[i]>numsSize/2)
            max = h->a[i];
    return max;
}
```