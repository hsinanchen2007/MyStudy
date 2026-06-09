偏移量给了20000是因为0<=|arr[i]-difference|<=|arr[i]|+|difference|=20000，过于恶意。之后遍历map只要从10000到30000就可以了。
```
int longestSubsequence(int* arr, int arrSize, int difference){
    int table[40001]={0};
    int i,result=0;
    for(i=0;i<arrSize;i++){
        table[arr[i]+20000]=table[arr[i]-difference+20000]+1;
        
    }
    for(i=10000;i<30001;i++){
        if(result<table[i]) result=table[i];
    }
    return result;

}

```
