### 解题思路
只有划水题才能这么顺利AC   :)

### 代码

```c
int cmp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int *tA = A + m;	//tA指向待插入位置
    while(n--)
    {
    	*tA++ = *B++;
    }
    qsort(A,ASize,sizeof(int),cmp);
    return 0;
}
```