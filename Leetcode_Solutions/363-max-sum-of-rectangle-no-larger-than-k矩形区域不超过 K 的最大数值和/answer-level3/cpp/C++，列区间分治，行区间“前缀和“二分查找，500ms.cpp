### 解题思路
C++，列区间分治，行区间“前缀和“二分查找（行区间同题解中其他二分查找方法）。值得注意的是，虽然列区间分治，
但并没有带来时间复杂度的减小，仍为O(n^2*m*lg(m)),m行n列。算是作为思维练习吧。

### 代码

```cpp
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        for(const auto& row: matrix)
        {
            preSum.push_back(vector<int>(1,0));
            auto& rowPreSum = preSum.back();
            for(const auto& i: row)
            {
                rowPreSum.push_back(rowPreSum.back() + i);
            }         
        }
        colS = vector<int>(matrix.size(), 0);
        maxI = numeric_limits<int>::min();
        maxSumK(0, matrix.front().size(), k);
        return maxI;
    }

    bool maxSumK(int beg, int End, int k)
    {
        if(beg + 1 == End)
        {
            for(int i=0;i<colS.size();++i)
                colS[i] = preSum[i][End] - preSum[i][beg];

            if(findMax(k))
                return true;
        }
        else
        {
            int mid = (beg + End) / 2;
            if(maxSumK(beg, mid, k))
                return true;

            if(maxSumK(mid, End, k))
                return true;
            
            int subBeg = beg;
            while(subBeg < mid)
            {
                for(int subEnd = mid + 1; subEnd <= End; ++subEnd)
                {
                    for(int i=0;i<colS.size();++i)
                        colS[i] = preSum[i][subEnd] - preSum[i][subBeg];

                    if(findMax(k))
                        return true;
                }
                ++subBeg;
            }
        }
        return false;
    }

    bool findMax(int k)
    {
        set<int> biSort;
        int sum = 0;
        biSort.insert(0);
        for(const auto& i: colS)
        {
            sum += i;
            auto iter = biSort.lower_bound(sum - k);
            if(iter != biSort.end())
            {
                int subSum = sum - *iter;
                if(subSum > maxI && subSum <= k)
                {
                    maxI = subSum;
                    if(subSum == k)
                        return true;
                }
            }
            biSort.insert(sum);
        }
        return false;
    }

    vector<vector<int>> preSum;
    vector<int> colS;
    int maxI;
};
```