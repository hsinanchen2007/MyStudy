void duplicateZeros(int* arr, int arrSize){
    int *B=(int*)malloc(sizeof(int)*arrSize);
    for(int i=0;i<arrSize;i++)
    {
        B[i]=arr[i];
    }
    int count=0;
    for(int i=0;i<arrSize-count;i++)
    {
        if(B[i]!=0)
        {   
            arr[i+count]=B[i];
        }
        else
        {
            arr[i+count]=0;
            count++;
            if(i+count<arrSize)
            arr[i+count]=0;
        }
    }
   
}