```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> S;
        for (auto iter = nums.begin(); iter != nums.end(); iter++)
        {
            if (S.find(*iter) != S.end())
            {
                S.erase(*iter);
            } else {
                S.insert(*iter);
            }
        }
        return *S.begin();
    }
};
```
异或
```
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int out = 0;
        for (auto it = nums.begin(); it != nums.end(); it++)
        {
            out = out ^ (*it);
        }
        return out;
    }
};
```