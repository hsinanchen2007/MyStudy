### 解题思路
- 核心要点：自定义cmp比较函数，不交换数组中的a和b当且仅当to_string(a)+to_string(b)<to_string(b)+to_string(a)
- 执行用时 :52 ms, 在所有 C++ 提交中击败了7.16%的用户
- 内存消耗 :11.1 MB, 在所有 C++ 提交中击败了100.00%的用户
### 代码

```cpp
class Solution {
public:
    static bool cmp(int a,int b){
        return to_string(a)+to_string(b)<to_string(b)+to_string(a);
    }
    string minNumber(vector<int>& nums) {
        string result;
        sort(nums.begin(),nums.end(),cmp);
        for(auto i:nums){
            result+=to_string(i);
        }
        return result;
    }
};
```