### 解题思路
此处撰写解题思路
倒序遍历存入A内就完了
### 代码

```c
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int p1=m-1;
    int p2=n-1;
    int cur=m+n-1;
    while(p1>=0&&p2>=0&&cur>=0)
    {
        A[cur--]=A[p1]>B[p2]?A[p1--]:B[p2--];
    }
    while(p1>=0&&cur>=0)
    {
        A[cur--]=A[p1--];
    }
    while(p2>=0&&cur>=0)
    {
        A[cur--]=B[p2--];
    }
}
```