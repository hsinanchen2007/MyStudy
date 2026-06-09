1.求和
2.求diff
3.使用diff在前导和中寻找，如果匹配，求max
```
/*
* Copyright (c) Nicolas-Tony Technologies Co., Ltd. 2019-2019. All rights reserved.
* Description: i love leetcode
* Author: Nicolas
* Create: 2019/09/25
*/
class Solution
{
public:
    int maxSubArrayLen(vector<int>& nums, int k)
    {
        // 和中有差，差中有和
        map<int, vector<int>> sumInfos;
        vector<int> indexs;
        indexs.push_back(-1);
        sumInfos.insert(make_pair(0, indexs));

        return calcMaxLength(nums, k, sumInfos);
    }

    int calcMaxLength(vector<int> &nums, int k, map<int, vector<int>> &sumInfos)
    {
        int maxLength = 0;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            int diff = sum - k;
            map<int, vector<int>>::iterator iter = sumInfos.find(diff);
            if (iter != sumInfos.end()) {
                vector<int> &indexs = iter->second;
                if (!indexs.empty()) {
                    int minLeftIndex = indexs.at(0);
                    maxLength = max(maxLength, i - minLeftIndex);
                }
            }
            insertSumInfos(sumInfos, sum, i);
        }
        return maxLength;
    }

    void insertSumInfos(map<int, vector<int>> &sumInfos, int sum, int i)
    {
        map<int, vector<int>>::iterator iter = sumInfos.find(sum);
        if (iter == sumInfos.end()) {
            vector<int> indexs;
            indexs.push_back(i);
            sumInfos.insert(make_pair(sum, indexs));
        } else {
            vector<int> &indexs = iter->second;
            indexs.push_back(i);
        }
    }

};
```
