### 解题思路


### 代码

```cpp
class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        unordered_map<int, int> map;
        int ans = 0;
        for(int i = 0, j = 0;i < A.size();++i){
            map[A[i]] ++;
            while(A[i] == 0 && map[A[i]] > K)
                map[A[j++]] --;
            ans = max(ans, i - j + 1);
        }
        return ans;
    }
};
```