### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i=0,j=A.size()-1;
       while(i<A.size()&&j>=0)
        {
            while(i<A.size()&&A[i]%2==0){
                i+=2;
            }
            while(j>=0&&A[j]%2==1){
                j-=2;
            }
            if(i<A.size()&&j>=0){
                int temp=A[i];
                A[i]=A[j];
                A[j]=temp;
            }
        }
        return A;
    }
};
```