### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        vector<int> vec(A.size(),0);
        int k=0,j=1;
        for(int i=0;i<A.size();i++){
            if(A[i]%2==0){
                vec[k]=A[i];
                k+=2;
            }   
            else{
                vec[j]=A[i];
                j+=2;
            }    
        }
        return vec;
    }
};
```