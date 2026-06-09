### 解题思路
过段时间在回来用stl解一次,这次性能很差 

### 代码

```cpp
class Solution 
{
public:
    #define val(x) x[0]+x[1]

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k)     
    {
        vector<vector<int>> q;

        for(int i:nums1)
            for(int j:nums2)
                q.push_back({i,j});
        
        if(q.size()<2) return q;

        int n=q.size(),ac=0;
        for(int i=n/2-1;i>=0;i--) sink(q,i,n); 
        while(ac<k && n>0)
        {
            swap(q[0],q[n-1]);
            sink(q,0,n-1);
            n--,ac++;
        }

        vector<vector<int>> res;
        while(k && !q.empty()) 
        {
            res.push_back(*(q.end()-1));
            q.pop_back();
            k--;
        }

        return res;
    }

    void sink(vector<vector<int>>& q,int pre,int n)
    {
        int minid=pre,left=2*pre+1,right=2*pre+2;

        while(left<n || right<n)
        {
            if(left<n && val(q[left])<val(q[minid])) minid=left;
            if(right<n && val(q[right])<val(q[minid])) minid=right;

            if(minid==pre) break;

            swap(q[pre],q[minid]);
            pre=minid,left=2*pre+1,right=2*pre+2;
        }
    }
};
```