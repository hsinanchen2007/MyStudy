左右同时遍历，i负责找到左边第一个奇数的下标，j负责找到右边第一个偶数的下标，然后交换。i,j继续相向而行。
```
 void swap(int *s,int i,int j)
 {
     int temp;
     temp=s[i];
     s[i]=s[j];
     s[j]=temp;
 }
int* sortArrayByParity(int* A, int ASize, int* returnSize){
    int i=0,j=ASize-1;
    while(i<j){
        while(A[i]%2==0&&i<j)
            i++;
        while(A[j]%2==1&&i<j)
            j--;
        swap(A,i,j);
        i++;
        j--;
    }
    *returnSize=ASize;
    return A;
}
```
