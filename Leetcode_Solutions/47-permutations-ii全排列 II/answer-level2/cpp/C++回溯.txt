### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
vector<int> candidates;
vector<vector<int>> myVecVec;
vector<int> paths;
vector<bool> isUsed;

void swap(int& left, int& right){
    int tmp = right;
    right = left;
    left = tmp;
}
void helper(int right){

    if(paths.size() == right){
        myVecVec.push_back(paths);
        return;
    }

    for (int i = 0; i < right; ++i) {
        if (i > 0 && candidates[i] == candidates[i - 1] && !isUsed[i - 1]) {
            continue;
        }
        if(!isUsed[i]){
            isUsed[i] = true;
            paths.push_back(candidates[i]);
            helper(right);
            paths.pop_back();
            isUsed[i] = false;
        }
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    candidates = nums;
    for (int i = 0; i < nums.size(); ++i) {
        isUsed.push_back(false);
    }
    int right = nums.size();

    helper(right);


    return myVecVec;

}
};
```