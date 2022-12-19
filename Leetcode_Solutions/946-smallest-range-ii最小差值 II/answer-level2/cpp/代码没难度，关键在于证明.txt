### 解题思路
从小到大进行排序，然后找到一个分割点，左边全部加K，右边全部减K。这是一种直觉上的想法，可以证明这种操作方法是最优的：
假如存在一种不符合以上规则的分法：A[i]加K，左边的某数A[j]减K，(j<i)，那么把A[j]减K变成加K至少不会让情况变得更糟。

### 代码

```cpp
class Solution {
public:
    int smallestRangeII(vector<int>& A, int K) {

        sort(A.begin(),A.end());
        int ans=A.back()-A.front();
        for(int i=0;i<A.size()-1;i++){
            ans=min(ans,max(A[i]+K,A.back()-K)-min(A.front()+K,A[i+1]-K));
        }
        return ans;
    }
};
```