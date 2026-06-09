### 解题思路


### 代码

```cpp
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if(nums1.size() == 0 || nums2.size() == 0)
            return vector<vector<int>>(0);
        priority_queue<Pair> q;
        int size1 = nums1.size(), size2 = nums2.size();
        for(int i = 0 ; i < size1 ; ++i)
        {
            for(int j = 0 ; j < size2 ; ++j)
            {
                q.push(Pair(nums1[i], nums2[j]));
            }
        }
        k = min(k, size1 * size2);
        vector<vector<int>> ans(k, vector<int>());
        for(int i = 0 ; i < k ; ++i)
        {
            Pair p = q.top();
            q.pop();
            ans[i].push_back(p.first);
            ans[i].push_back(p.second);
        }
        return ans;
    }
private:
    struct Pair{
        int first, second;
        friend bool operator < (Pair a, Pair b)
        {
            return (a.first + a.second) > (b.first + b.second);
        }
        Pair(int _first, int _second) : first(_first), second(_second){}
    };
};
```