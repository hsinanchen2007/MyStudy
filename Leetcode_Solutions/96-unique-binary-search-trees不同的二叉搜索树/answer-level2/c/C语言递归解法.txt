```
int getNums(int left, int right){
    if(left == right || left+1 == right){
        return 1;
    }
    int sum = 0;
    for(int i = left; i < right; i++){
        sum += getNums(left,i)*getNums(i+1,right);
    }
    
    return sum;
}

int numTrees(int n){
    return getNums(1,n+1);
}
```
