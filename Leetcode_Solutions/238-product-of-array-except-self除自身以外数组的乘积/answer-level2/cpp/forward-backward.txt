### 解题思路
执行用时 :
16 ms
, 在所有 C++ 提交中击败了
70.48%
的用户
内存消耗 :
17.1 MB
, 在所有 C++ 提交中击败了
5.10%
的用户

### 代码

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> forward;
        int k = 1;
        for(int i = 0; i < n; i++){
            forward.push_back(k);
            k *= nums[i];
        }
        k = 1;
        for(int i = n-1; i >= 0; i--){
            forward[i] = k * forward[i];
            k = k * nums[i];
        }
        return forward;
    }
};
```