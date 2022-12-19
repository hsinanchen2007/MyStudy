### 解题思路
首先将给定数组排序，然后遍历，因为是排序好的，如果加上当前元素大于给定的值，则后面都不用遍历了，
还要去除掉重复的组合情况，由于是排序好的，所以只要后面的数字比放入数组中的最后一个小，则说明这个元素前面已经考虑过了所有情况，直接跳过就行了。
![image.png](https://pic.leetcode-cn.com/1d1a854404dbbd3d37ce2d70a01c6c31cab2c91c20c4825a3bb241e986ea3c65-image.png)


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> retVec;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.size() == 0 ) return retVec;
        std::sort(candidates.begin(), candidates.end());
        vector<int> tempvec;
        combinationSumInternal(candidates, tempvec, target, 0);
        return retVec;
    }

    void combinationSumInternal(vector<int>& candidates, vector<int>& vec, int target, int sum)
    {
        if(sum == target) 
        {
            retVec.push_back(vec);
            return;
        }
        for(int i = 0; i < candidates.size(); i++)
        {
            if(sum+candidates[i] > target )
            {
                return;
            }
            if(vec.size() > 0 && candidates[i] < vec[vec.size()-1])
            {
                continue;
            }
            vec.push_back(candidates[i]);
            combinationSumInternal(candidates, vec, target, sum+candidates[i]);
            vec.pop_back();
        }
    }
};
```