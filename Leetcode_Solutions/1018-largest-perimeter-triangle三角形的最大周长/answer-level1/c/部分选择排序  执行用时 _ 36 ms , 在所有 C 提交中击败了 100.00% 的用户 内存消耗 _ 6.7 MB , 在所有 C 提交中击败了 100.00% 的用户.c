```
代码块
int cmp(void * a, void * b){
    return *(int *)a < *(int *)b;
}

void swap(int * a, int * b){
    int tmp = *a;
    * a = * b;
    * b = tmp;
}

int largestPerimeter(int* A, int ASize){

// 执行用时 : 48 ms , 在所有 C 提交中击败了 87.60% 的用户 内存消耗 : 7.4 MB , 在所有 C 提交中击败了 100.00% 的用户
/*
    qsort(A, ASize, sizeof(int), cmp);
    int i = 0;
    while(i < ASize - 2){
        if(A[i] < A[i + 1] + A[i + 2])){
            return A[i] + A[i + 1] + A[i + 2];
        }
        i ++;
    }
    return 0;
*/

    //选择排序 找最大的三个
//执行用时 : 36 ms , 在所有 C 提交中击败了 100.00% 的用户 内存消耗 : 6.9 MB , 在所有 C 提交中击败了 100.00% 的用户
    int a = 0;
    int b = 0;
    int c = 0;
    
    int i, j, k;
    
    int index = 0;
    int tmp = index;
    for(i = index; i < ASize; ++ i){
        if(A[i] > a){
            a = A[i];
            tmp = i;
        }
    }
    swap(A + index, A + tmp);

    tmp = index + 1;
    for(j = index + 1; j < ASize; ++ j){
        if(A[j] > b){
            b = A[j];
            tmp = j;
        }
    }
    swap(A + index + 1, A + tmp);
    
    while(index < ASize - 2){    
        tmp =  index + 2;
        for(k = index + 2; k < ASize; ++ k){
            if(A[k] > c){
                c = A[k];
                tmp = k;
            }
        }
        swap(A + index + 2, A + tmp);

        if(c + b > a){
            return a + b + c;
        }else{
            index ++;
            a = b;
            b = c;
            c = 0;
        }
    }
    return 0;
}
```
