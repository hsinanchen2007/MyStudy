执行用时 :36 ms, 在所有 C++ 提交中击败了97.31%



```cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        vector<int>::iterator it=lower_bound(nums.begin(),nums.end(),target);
        if(it==nums.end())return -1;
        if(*it==target)return it-nums.begin();
        else return -1;

    }
};
```