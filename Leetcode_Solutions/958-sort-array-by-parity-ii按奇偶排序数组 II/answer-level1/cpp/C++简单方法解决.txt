执行用时 :
120 ms
, 在所有 C++ 提交中击败了
91.15%
的用户
```c++ []
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> odd;
        vector<int> even;
        for(int i=0;i<A.size();i++){
            if(A[i]%2)odd.push_back(A[i]);
            else even.push_back(A[i]);
        }
        for(int i=0,j=0,k=0;i<A.size();i++)
        {
          if(i%2)
              A[i]=odd[j++];
            else A[i]=even[k++];
        }
        return A;
    }
};
```
```c++ []

```

