### 解题思路
总算没有超时了，时间和内存指标基本垫底。
看了一下题解，基本都是双指针的算法，开始还以为自己的算法很完美，不需要什么双指针，提交几次超时后才发现不用双指针不行。。。
其实双指针的算法跟快速排序的思想有点类似，跟大多数题解不同的是，俺是把任意两个数的和以及他们的下标先保存到一个vector里面，转换为两数之和进行处理，关键就是要去重了。


### 代码

```cpp
using namespace std;

typedef struct {
    int value;
    vector<int> twoNumsSet;
} TwoNums;

bool CmpNum(TwoNums &a, TwoNums &b)
{
    return a.value < b.value;
}

class Solution {
public:
    vector<int> CreateNums(vector<int>& nums, vector<int> &idxs)
    {
        vector<int> newNums;
        for (auto i : idxs) {
            newNums.push_back(nums[i]);
        }

        return newNums;
    }

    vector<vector<int>> RemoveRepeat(vector<vector<int>> &orgNums)
    {
        set<vector<int>> s(orgNums.begin(), orgNums.end());
        vector<vector<int>> newNums;
        newNums.assign(s.begin(), s.end());
        return newNums;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> results;
        int size = nums.size();
        if (size < 4) {
            return results;
        }

        sort(nums.begin(), nums.end());

        vector<TwoNums> twoNumsSum;
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                TwoNums tmp;
                tmp.twoNumsSet.push_back(i);
                tmp.twoNumsSet.push_back(j);
                tmp.value = nums[i] + nums[j];
                twoNumsSum.push_back(tmp);
            }
        }

        sort(twoNumsSum.begin(), twoNumsSum.end(), CmpNum);

        vector<set<int>> fourNums;
        int low = 0;
        int high = twoNumsSum.size() - 1;
        while (low < high) {
            int tmpSum = twoNumsSum[low].value + twoNumsSum[high].value;
            if (tmpSum == target) {
                int tmpLow = low + 1;
                int tmpHigh = high - 1;
                vector<int> sameLow;
                vector<int> sameHigh;
                sameLow.push_back(low);
                sameHigh.push_back(high);
                while ((twoNumsSum[tmpLow].value == twoNumsSum[low].value) && (tmpLow < high)) {
                    sameLow.push_back(tmpLow);
                    tmpLow++;
                }                
                low = tmpLow;

                while ((twoNumsSum[tmpHigh].value == twoNumsSum[high].value) && (low < tmpHigh)) {
                    sameHigh.push_back(tmpHigh);
                    tmpHigh--;
                }
                high = tmpHigh;

                for (int i = 0; i < sameLow.size(); i++) {
                    for (int j = 0; j < sameHigh.size(); j++) {
                        set<int> tmp;
                        int idx1 = sameLow[i];
                        int idx2 = sameHigh[j];
                        tmp.insert(twoNumsSum[idx1].twoNumsSet[0]);
                        tmp.insert(twoNumsSum[idx1].twoNumsSet[1]);
                        tmp.insert(twoNumsSum[idx2].twoNumsSet[0]);
                        tmp.insert(twoNumsSum[idx2].twoNumsSet[1]);
                        fourNums.push_back(tmp);
                    }
                }

                continue;
            }

            if (tmpSum < target) {
                low++;
                continue;
            }

            high--;
        }

        for (int i = 0; i < fourNums.size(); i++) {
            if (fourNums[i].size() == 4) {
                vector<int> tmp;
                tmp.assign(fourNums[i].begin(), fourNums[i].end());
                vector<int> tmpNums = CreateNums(nums, tmp);
                results.push_back(tmpNums);
            }
        }

        vector<vector<int>> newResults = RemoveRepeat(results);

        return newResults;
    }
};
```