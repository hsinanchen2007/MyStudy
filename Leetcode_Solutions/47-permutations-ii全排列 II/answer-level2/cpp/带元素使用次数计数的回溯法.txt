### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
                vector<vector<int>> output;
    
    unordered_map<int,int> frequence;
    
    //去重的字符种类
    unordered_set<int> allNums;
    //获得每个数字出现频率的map
    int size = nums.size();
    for (int i = 0; i != size; i++) {
        frequence[nums[i]]++;
        allNums.insert(nums[i]);
    }
    
    vector<int> draft;
    draft.reserve(size);
    
    permuteUnique(draft, allNums,frequence, 0, size, output);
    return output;

    }

    void permuteUnique(vector<int> &currentResult,unordered_set<int> &nums,unordered_map<int,int> &frequence,int currentIndex,int objSize,vector<vector<int>> &output){
    if (currentResult.size() == objSize) {
        output.push_back(currentResult);
        return;
    }
    //
        //添加自己的阶段的尝试，自己阶段不能添加与上一个阶段添加的相同的数字。
        for (unordered_set<int>::iterator i = nums.begin(); i != nums.end(); i++) {
            bool nonSameWithLast = currentIndex == 0 || currentResult.back() != *i;
            if (nonSameWithLast && frequence[*i]) {
                //当前有存量，且不与当前结果的最尾部数字相同的数字，可以进行尝试
                int frequenceOfCurrrentCandiate = frequence[*i];
                //重复频率正好和结果剩余的长度完全吻合，则不进行回溯，直接添加，取得结果。
                if (frequenceOfCurrrentCandiate == objSize - currentIndex) {
                    currentResult.insert(currentResult.end(), frequenceOfCurrrentCandiate, *i);
                    output.push_back(currentResult);
                    currentResult.erase(currentResult.end() - frequenceOfCurrrentCandiate, currentResult.end());
                    return;
                }
                //否则从尝试当前字符重复几次
                for (int duplicateCount = 1; duplicateCount <= frequenceOfCurrrentCandiate; duplicateCount++) {
                    currentResult.insert(currentResult.end(), duplicateCount, *i);
                    frequence[*i] -= duplicateCount;
                    //进行下一步的尝试
                    if (currentResult.size() == objSize) {
                        output.push_back(currentResult);
                    }
                    else
                    {
                        permuteUnique(currentResult,nums, frequence, currentIndex+duplicateCount, objSize, output);
                    }
                    //进行回溯
                    currentResult.erase(currentResult.end() - duplicateCount, currentResult.end());
                    frequence[*i] += duplicateCount;
                }
            }
        }
}



};
```