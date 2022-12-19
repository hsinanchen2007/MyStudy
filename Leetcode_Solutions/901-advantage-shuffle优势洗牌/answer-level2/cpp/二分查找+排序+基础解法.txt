### 解题思路
1.  以B数组为基准，从前往后查找；
先对A进行排序，然后在去A里面二分查找第一个大于B[i]的数，然后删除该数；如果找不到比B[i]大的数，就用最小的数去“赛马”。
2.  参考标准解法，利用贪心思想，如果A中的最小值大于B的最小值，它们就可以对上；如果A的最小值不敌B的最小值，那么它就负责消灭B的最大值；  解的时候注意需要保存一个index和value的vector~


### 代码

```cpp
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        sort(A.begin(), A.end());
        vector<int> ans;
        for (int i = 0; i < B.size(); i++) {
            auto iter = upper_bound(A.begin(), A.end(), B[i]);
            if (iter != A.end()) {
                ans.push_back(*iter);
                A.erase(iter);
            } else {
                ans.push_back(A[0]);
                A.erase(A.begin());
            }
        }
        return ans;
    }
};


class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<pair<int, int>> numIndex;
        for (int i = 0; i < B.size(); i++) {
            numIndex.push_back(make_pair(B[i], i));
        }
        sort(numIndex.begin(), numIndex.end(), [](pair<int, int> a, pair<int, int> b) {
            return a.first < b.first;
        });
        sort(A.begin(), A.end());
        vector<int> ans(A.size(), 0);
        int bIndex = 0;
        for (int i  = 0; i < A.size(); i++) {
            if (A[i] > numIndex[bIndex].first) {
                ans[numIndex[bIndex].second] = A[i];
                bIndex++;
            } else {
                ans[numIndex.back().second] = A[i];
                numIndex.pop_back();
            }
        }
        return ans;
    }
};
```