### 解题思路
   首先想到的应该是对数组进行排序，从小到大如果有负数就对负数取反，如果没有负数就一直对最小的那个数取反，一直到k为0；
      然后遍历一般数组A，返回总和sum。

### 代码

```cpp
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(),A.end());
        for(int i=0;i<A.size();i++){
            if(A[i]<0&&K>0){
                A[i]=-A[i];
                K--;
            }
        }

        sort(A.begin(),A.end());
        while(K){
            A[0]=-A[0];
            K--;
        }
        int sum=0;
        for(int j=0;j<A.size();j++){
          sum+=A[j];
        }
          return sum;
    }
};
```