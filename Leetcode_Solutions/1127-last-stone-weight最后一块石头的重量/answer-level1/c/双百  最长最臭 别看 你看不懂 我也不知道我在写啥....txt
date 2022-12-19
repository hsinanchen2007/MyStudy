```
void quick_sort(int *org_arr,int begin,int end)
{
    int low = begin;
    int high = end;
    int x = org_arr[low];

    while(low < high)
    {
        while(low < high && x < org_arr[high])
        {
            high--;
        }
        if(low < high)
        {
            org_arr[low++] = org_arr[high];
        }

        while(low < high && x > org_arr[low])
        {
            low++;
        }
        if(low < high)
        {
            org_arr[high--] = org_arr[low];
        }
        org_arr[low] = x;

        quick_sort(org_arr,begin,low - 1);        
        quick_sort(org_arr,low + 1,end);        
    }
    
}

void insert_num(int* insert_num,int num,int num_size)
{
    insert_num[num_size] = num;
    quick_sort(insert_num,0,num_size);
}
    
int lastStoneWeight(int* stones, int stonesSize){
    int index = stonesSize - 1;
    int back_num = 0;    //向前平移位数
    if(stonesSize <= 1)
    {
        return stones[0];
    }
    
    //快排
    quick_sort(stones,0,stonesSize - 1);

    while(index >= 1){
        int diff = stones[index] - stones[index - 1];
        if(diff == 0)
        {
            back_num = 2;
        }else{
            back_num = 1;
            insert_num(stones,diff,index - 1);
        }
        index -= back_num;
    }

    if(index == 0)
    {
        return stones[0];
    }else{
        return stones[1] - stones[0];
    }
}
```
