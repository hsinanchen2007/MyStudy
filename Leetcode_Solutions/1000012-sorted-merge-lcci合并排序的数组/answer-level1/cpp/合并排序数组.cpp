### 解题思路
定义三个下标i,j,k，分别指向A数据尾部、B数据尾部、存放的尾部，每次比较A[i]与B[j],取较大的存放到A[k],下标递减。
好处是不占用额外的存储空间。
### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i=m-1,j=n-1,k=m+n-1;
        while(k>-1){
            if(j<0||(i>-1&&A[i]>B[j])){
                A[k]=A[i];
                k--;
                i--;
            }
            else{
                A[k]=B[j];
                j--;
                k--;
            }
        }
    }
};
```