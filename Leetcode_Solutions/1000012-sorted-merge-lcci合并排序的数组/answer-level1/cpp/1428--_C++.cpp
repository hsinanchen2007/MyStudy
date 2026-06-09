### 解题思路
创建新数组来暂存之后进入的元素
### 代码

```cpp
class Solution{
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n){
        int pa=0,pb=0;
        int sorted[m+n]={0};
        int cur;
        while(pa<m||pb<n)
        {
            if(pa==m)
                cur=B[pb++];
            else if(pb==n)
                cur=A[pa++];
            else if(A[pa]<B[pb])
                cur=A[pa++];
            else 
                cur=B[pb++];
            sorted[pa+pb-1]=cur;
        }
        for(int i=0;i!=m+n;++i)
            A[i]=sorted[i];
    }
};
```