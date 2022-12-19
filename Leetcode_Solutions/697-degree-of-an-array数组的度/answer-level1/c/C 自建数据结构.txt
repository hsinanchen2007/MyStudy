```

typedef struct
{
    int cnt;
    int left;
    int right;
}Item;

#define MAX_LEN 50001

Item map[MAX_LEN];

#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)

int findShortestSubArray(int* nums, int numsSize){

    int degree = 0;

    memset(map, 0, sizeof(map));

    for(int i = 0; i < numsSize; i++)
    {
        Item *item = map + nums[i];

        if(item->cnt == 0) item->left = i;  // init left index

        item->right = i;    // record right index
        (item->cnt)++;

        degree = max(item->cnt, degree);
    }

    int shortest = INT_MAX;
    
    for(int i = 0; i < MAX_LEN; i++)
    {
        Item *item = map + i;

        if(item->cnt == degree)
            shortest = min(shortest, item->right - item->left + 1);
    }

    return shortest;
}

```
