### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    struct cmp
    {
        bool operator() (const pair<int,vector<int> >& a, const pair<int,vector<int> >& b)
        {
            return a.first>b.first;
        }
    };

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        priority_queue<pair<int,vector<int> >, vector<pair<int,vector<int> > >, cmp> pq;

        for(int n1:nums1)
        {
            for(int n2:nums2)
            {
                vector<int> tmp_v={n1,n2};
                int tmp_sum=n1+n2;
                pq.push(make_pair(tmp_sum,tmp_v));
            }
        }

        vector<vector<int>> res;
        for(int i=0; !pq.empty() && i<k; ++i)
        {
            auto p=pq.top();
            pq.pop();
            res.push_back(p.second);
        }

        return res;
    }
};
```