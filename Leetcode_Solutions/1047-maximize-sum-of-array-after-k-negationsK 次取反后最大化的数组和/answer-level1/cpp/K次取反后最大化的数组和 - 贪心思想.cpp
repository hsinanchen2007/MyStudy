### 解题思路
1. 进行K次取反操作，每次取排序后数组中第一个元素取反(即最小值取反)
2. 计算K次取反后的数组和

### 代码

```cpp
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        int ans = 0;
        while(K > 0){
            sort(A.begin(), A.end());
            A[0]  = - A[0];
            K--;
        }
        for(int n: A) ans += n;
        return ans;
        
    }
};
```