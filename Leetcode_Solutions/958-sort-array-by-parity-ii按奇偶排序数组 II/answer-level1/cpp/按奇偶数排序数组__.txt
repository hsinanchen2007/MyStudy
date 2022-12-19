### 解题思路
  可以先创建一个数组，然后对数组A 进行遍历，然后如果A[i]是偶数，则按0，2，4，6...的顺序把A[i]放入创建的数组中；
     如果A[i]是奇数，则按照1，3，5，7，9...的顺序把A[i]放入创建的数组中。然后输出这个创建的数组。

### 代码

```cpp
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
      vector<int>B(A.size());
    
      int s=0;
      int d=1;
      for(int i=0;i<A.size();i++){
          if(A[i]%2==0){
             B[s]=A[i];
             s+=2;
          }
          if(A[i]%2!=0){
              B[d]=A[i];
              d+=2;
          }
      }
   
       return B; 
    }
};
```