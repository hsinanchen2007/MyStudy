### 解题思路
此处撰写解题思路
双指针将就着看吧。
### 代码

```cpp
class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
     vector<int>p(m+n,0);
     int j=0,l=0;
     for(int i=0;i<m+n;i++)
     { if(l==n)
         {
             p[i]=A[j];
             j++;
         }
        else if(j==m)
         { 
             p[i]=B[l];
            l++;
         }
        
       else if(A[j]<B[l])
       {
           p[i]=A[j];
           j++;
       }
      else {
           p[i]=B[l];
           l++;
       }
     }
     for(int z=0;z<m+n;z++)
     {
         A[z]=p[z];
     }
    }
};
```