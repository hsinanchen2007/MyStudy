### 解题思路
一种比较直观的解法。比较不容易想到的地方在与更新的方式：max(temp+1-(A[i]-A[i-1]),0)

### 代码

```cpp
class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        // 先排序，然后遍历时，先判断是否是重复值
        int res = 0;
        int len = A.size();
        if(len<2) return res;
        sort(A.begin(),A.end());
        int temp = 0;
        for(int i=1;i<len;i++){
            temp = max(temp+1-(A[i]-A[i-1]),0);
            res += temp;
        }
        return res;
    }
};
```