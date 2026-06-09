void dts(int n,int **flights, int flightsSize,int src, int dst, int K,int *len,int *min,int * cur,int *ptr,int** ptr1,int*ptr2)
{
    int i = 0;
    int tmp = 0;
    int index = 0;
    
    if(ptr[src] != 0)
    {
        return;
    }
    if((*len) > K)
    {
        return;
    }
    if(*cur > *min)
    {
        return;
    }

    ptr[src] = 1;
    for(i = 0; i < ptr2[src]; i++)
    { 
        index = ptr1[src][i];
        (*len)++;
        *cur += flights[index][2];
        tmp = flights[index][2];
        if(ptr[flights[index][1]] != 2)
        {
            if(flights[index][1] == dst)
            {
                if((*len) <= K)
                {
                    if(*min > *cur)
                    {
                        *min = *cur;
                    }
                }
            }
            else
            {
                dts(n,flights,flightsSize,flights[index][1],dst,K,len,min,cur,ptr,ptr1,ptr2);
            }
            *cur -= tmp;
            (*len)--;
        }
            
    }
    ptr[src] = 0;
}
int findCheapestPrice(int n, int** flights, int flightsSize, int* flightsColSize, int src, int dst, int K){
    int *ptr = NULL;
    int lenght = -1;  
    int min_value = 0xFFFFFFF;
    int cur_value = 0;
    int **ptr1 = NULL;
    int *ptr2 = NULL;
    int index = 0;
    
    ptr = malloc(sizeof(int) * n);
    memset(ptr,0, sizeof(int) * n);
    ptr2 = malloc(sizeof(int) * n);
    memset(ptr2,0, sizeof(int) * n);

    ptr1 = malloc(sizeof(int*) * n);
    memset(ptr1,0, sizeof(int) * n);

    for(int i = 0; i< n;i++)
    {
        ptr1[i] = malloc(flightsSize *sizeof(int));
    }
    for(int i = 0; i < flightsSize; i++)
    {
        index = flights[i][0];
        ptr1[index][ptr2[index]] = i;
        ptr2[index]++;
    }

    

    dts(n,flights,flightsSize,src,dst,K,&lenght,&min_value,&cur_value,ptr,ptr1,ptr2); 
    if(min_value !=  0xFFFFFFF)
    {
        return min_value;
    }
    else
    {
        return -1;
    }
    
}