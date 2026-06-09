我觉得是比较巧妙的方法：
```
bool canThreePartsEqualSum(int* A, int ASize){
    int sum = 0;
    for(int i = 0;i < ASize;i++){
        sum += A[i];
    }
    
    if(sum%3 != 0){
        return false;
    }
    
    int a = sum/3;
    int sums = 0,cnt = 0;
    for(int i=0;i<ASize;i++){
        sums+=A[i];
        if(sums==a){
            cnt++;
            sums=0;
        }
    }
    if(cnt==3 && sums == 0){
        return true;
    }
    return false;
}


```
