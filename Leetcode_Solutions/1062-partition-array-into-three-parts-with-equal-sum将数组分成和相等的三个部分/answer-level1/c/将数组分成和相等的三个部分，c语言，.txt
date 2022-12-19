### 解题思路
前中后都等于sum/3就true

### 代码

```c
bool canThreePartsEqualSum(int* A, int ASize){
    if(ASize < 3){
        return false;
    }
    int sum=0,middle=0,front=A[0],rear=A[ASize-1];
    for(int i=0;i<ASize;i++){
        sum += A[i];
    }
    if(sum%3 != 0){
        return false;
    }
    middle = sum-front-rear; 
    sum /= 3;
    for(int i=0,j=ASize-1;i+1<j;){
        if(front==sum && rear==sum){
            if(middle == sum){
                return true;
            }else{
                return false;
            }
        }else{
            if(front != sum){
                front += A[++i];
                middle -= A[i];
            }
            if(rear != sum){
                rear += A[--j];
                middle -= A[j];
            }
        }
    }
    return false;
}
```