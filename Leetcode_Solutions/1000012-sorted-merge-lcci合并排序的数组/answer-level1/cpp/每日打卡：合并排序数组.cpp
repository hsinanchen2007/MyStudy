### 解题思路
有序数组的合并实际上就是一个如何比较其中元素大小的问题，由于数组的有序性，当比较A[i]与B[j]的大小时，找到A[i]>B[j]时，该位置将让与B[j]，而A[i]及其后数据统一后移一个位置；又由于B有序，则B[j+1]只需要与A[i+1]以后的元素继续比较大小即可。当遍历完A中元素后，说明B中剩余元素比A中元素都大，则B中剩下的元素直接插入A后即可。

### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        for(int i=0,j=0;i<m+n&&j<n;){
            if(i==m+j){
                while(i<m+n){
                    A[i]=B[j];
                    ++i;
                    ++j;
                }   
            }else if(A[i]<=B[j]){
                ++i;
            }else{
                for(int k=m+n-1;k>i;--k){
                    A[k]=A[k-1];
                }
                A[i]=B[j];
                ++i;
                ++j;
            }
        }
    }
};
```