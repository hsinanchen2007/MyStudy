### 解题思路
先按照升序排序，找到震荡的规律
1 2 3 4 5 6 这种类型的规律如下
  4  5  6
1  2  3

4 5 5 5 6 6 这种规律如下：
   6   6   5
5   5   4

### 代码

```c
int compare(int* a, int*b){
    return *a-*b;
}
void wiggleSort(int* nums, int numsSize){
    int *tmp;

    if(nums == NULL || numsSize == 0){
        return;
    }

    tmp = (int*)malloc(sizeof(int)*numsSize);
    memset(tmp,0,sizeof(int)*numsSize);

    qsort(nums,numsSize,sizeof(int),compare);


    if(numsSize%2 == 0){
        //tmp[0] = nums[0];
        int j = 0;
        if(nums[numsSize/2-1] == nums[numsSize/2]){        
           for(int i = (numsSize/2)-1; i >= 0 ;i--){
                tmp[j] = nums[i];
                //printf("tmp %d, j %d",tmp[j],j);     
                j += 2;                  
            }
            j = 1;
            for(int i = numsSize-1; i >= numsSize/2; i--){
                tmp[j] = nums[i];
                //printf("tmp %d, j %d",tmp[j],j);     
                j += 2;
            } 
        }else{
            for(int i = 0; i < (numsSize/2);i++){
                tmp[j] = nums[i];
                j += 2;
            
            }
            j = 1;
            for(int i = numsSize/2; i < numsSize; i++){
                tmp[j] = nums[i];
                j += 2;
            }
        }


    }else{
        tmp[numsSize-1] = nums[0];
        int j = 0;
        for(int i = 1; i < ((numsSize+1)/2);i++){
            tmp[j] = nums[i];
            //printf("j %d nu %d\r\n",j,tmp[j]);
            j += 2;
           
        }
        j = 1;
        for(int i = ((numsSize+1)/2); i < numsSize; i++){
            tmp[j] = nums[i];
            //printf("j %d nu %d\r\n",j,tmp[j]);
            j += 2;
          
        }
    }

    for(int i= 0; i < numsSize; i++){
        nums[i] = tmp[i];
    }
    free(tmp);
    return;

}
```