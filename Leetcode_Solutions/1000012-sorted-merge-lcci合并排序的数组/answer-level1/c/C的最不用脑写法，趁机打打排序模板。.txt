### 解题思路
感觉可以直接合并然后快排，其他的方法最快差个log，而且对于写C的这是个打快排的好机会。
### 代码

```c
void q_sort(int left, int right, int v[]){
    int l = left, r = right, x = v[(left+right)/2];
    while(l <= r){
        while(v[l] < x) l++;
        while(v[r] > x) r--;
        if(l <= r){
            int tmp = v[l];
            v[l] = v[r];
            v[r] = tmp;
            l++, r--;
        }
    }
    if(l < right) q_sort(l, right, v);
    if(left < r) q_sort(left, r, v);
}
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int j = 0;
    for(int i = m; i < ASize; i++){
        A[i] = B[j];
        j++;
    }
    q_sort(0, ASize-1, A);
}
```