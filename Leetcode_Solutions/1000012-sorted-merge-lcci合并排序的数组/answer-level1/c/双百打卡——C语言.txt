### 解题思路
就两个数组的元素比较大小，然后排序嘛~用一个辅助数组来装排好序的合并数组，再装回原来的A数组就好了。

讲道理，是不是没人用C写啊，我这个内存消耗7.4MB，也能击败100%的用户？？？

### 代码

```c
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int* C;
    C = (int *)malloc(ASize*sizeof(int));
    int i=0,j=0,k=0;
    int label;
    label = m+n;
    int diff;
    if(n>0){
        for(label;label>0;label--){
            if(i<m && j<n){
                diff = *(A+i) - *(B+j);
                if(diff<0){
                    *(C+k) = *(A+i);
                    i++;
                    k++;
                }else if(diff>=0){
                    *(C+k) = *(B+j);
                    j++;
                    k++;
                }
            }else if(i>=m && j<n){
                *(C+k) = *(B+j);
                j++;
                k++;
            }else if(i<m && j>=n){
                *(C+k) = *(A+i);
                i++;
                k++;
            }
        }
        for(i=0;i<(m+n);i++){
            *(A+i) = *(C+i);
        }
    }else{}
}
```