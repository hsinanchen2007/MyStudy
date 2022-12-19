```
int candy(int* ratings, int ratingsSize){
    int *ret = (int *)malloc(sizeof(int)*ratingsSize);
    int count = 0;
    for(int i = 0; i<ratingsSize;i++){
        ret[i] = 1;
    }
    for (int i= 1 ;i < ratingsSize ; i++){
        if (ratings[i]>ratings[i-1]){
            ret[i]=ret[i-1] + 1;
        }
    }
    for (int i = ratingsSize - 2;i>= 0;i--){
        if(ratings[i]>ratings[i+1]){
            ret[i]=ret[i]>(ret[i+1]+1)?ret[i]:(ret[i+1]+1);
        }
    }
    for (int i = 0; i < ratingsSize ;i++){
        count+=ret[i];
    }
    return count;
}
```
