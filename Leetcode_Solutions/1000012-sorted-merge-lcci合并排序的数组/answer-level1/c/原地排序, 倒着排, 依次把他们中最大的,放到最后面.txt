### 解题思路
此处撰写解题思路

### 代码

```c
void merge(int *A, int ASize, int m, int *B, int BSize, int n)
{
    int pointA = m-1;
    int pointB = n-1;
    int cur = n+m-1;
    while(pointA>-1&&pointB>-1){
       if(A[pointA]>B[pointB]){
           A[cur] = A[pointA];
           pointA--;
           
       }else{
            A[cur] = B[pointB];
            pointB--;
        }
       cur--;
    }
    if(pointB>-1)
        for(int i=0;i<=pointB;i++)
            A[i] = B[i];
        
}
```