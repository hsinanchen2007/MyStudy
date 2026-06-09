```
int partitionDisjoint(int* A, int ASize){

    int max = 0;
    int tmp_max = 0;
    int pos1 = 0;
    int pos2 = 0;
    int tmp_flg = 0;
    if(ASize < 1)
    {
        return 0;
    }

    max = A[0];
    tmp_max = max;
    pos1 = 0;
    for(int i = 0; i < ASize; i++)
    {
       if(A[i] < max)
       {
           if(tmp_flg == 1)
           {
               max = tmp_max;
               pos2 = i;
           }
           pos1 = i;
       }
       else
       {
           if(tmp_flg == 0)
           {
               tmp_flg = 1;
               tmp_max = A[i];
               pos2 = i;
           }
           else
           {
               if(tmp_max < A[i])
               {
                   tmp_max = A[i];
               }
           }
       }
    }

    if(pos1 > pos2)
    {
        return pos1 + 1;
    }

    return pos2 + 1;
}
```
