### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
private:
    set<vector<int>> vectResSet;

public:
    void helper(vector<vector<int>> *vectInt, vector<int> nums, int intPos, int intLen, vector<bool> visivted){
        vector<int>::iterator iter;
        int iTmp;

        if (intPos == intLen ) {
            vectResSet.insert(nums);
            return;
        }

        iTmp = nums[intPos];
        iter = nums.begin();
        nums.erase(nums.begin() + intPos);

        for (int i = 0; i <= intPos; i++, iter++){
            nums.insert(iter,iTmp);

            helper(vectInt,nums,intPos + 1, intLen,visivted);

            nums.erase(iter);
        }

        return;
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int intPos = 0;
        vector<vector<int>>::iterator iter;
        vector<vector<int>> *intVect = new vector<vector<int>>;
        vector<bool> visited(nums.size(),false);

        sort(nums.begin(), nums.end());

        helper(intVect,nums,intPos,nums.size(),visited);

        for (auto i:vectResSet){
            intVect->push_back(i);
        }

        return *intVect;
    }
};
```