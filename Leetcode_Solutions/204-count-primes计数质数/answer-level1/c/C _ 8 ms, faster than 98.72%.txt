```
int countPrimes(int n){

    if(n<=2)return 0;
    
    int sq=sqrt(n);
    
    bool *arr=(bool*)calloc(n,sizeof(bool));
    for(int i=3;i<=sq;i+=2){
        if(arr[i]){
            continue;
        }
        else{
            for(int j=i*i;j<n;j+=2*i){
                arr[j]=true;
            }
        }
    }
    
    int sum=1;
    
    for(int i=3;i<n;i+=2){
         if(arr[i]==false){
             sum++;
         }
    }
    free(arr);
    
    return sum;
}
```