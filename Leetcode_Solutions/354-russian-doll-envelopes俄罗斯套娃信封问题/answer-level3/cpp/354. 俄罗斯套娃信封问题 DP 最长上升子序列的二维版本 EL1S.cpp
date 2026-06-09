这道题有意思，其实就是[300题](https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/300-zui-chang-shang-sheng-zi-xu-lie-el1s-by-el1s-2/)的二维版本

用二维的做法做了之后才发现原来这道题可以简化为一维版本
二维
```
static bool myfunc(vector<int> a, vector<int> b)
{
    if(a[0] < b[0] && a[1] && b[1])
        return true;
    else
        return a[0] < b[0];
}
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        if(!n) return 0;
        vector<vector<vector<int>>> tail;
        sort(envelopes.begin(), envelopes.end(), myfunc);
        for(int i = 0; i < n; i++)
        {
            if(!tail.size())
            {
                tail.push_back({});
                tail[0].push_back(envelopes[i]);
                continue;
            }
            bool b = false;
            for(auto x: tail.back())
            {
                if(envelopes[i][0] > x[0] && envelopes[i][1] > x[1])
                {
                    tail.push_back({});
                    tail[tail.size() - 1].push_back(envelopes[i]);
                    b = true;
                    break;
                }
            }
            if(b) continue;
            
            int l = 0, r = tail.size() - 1;
            while(l < r)
            {
                int mid = (l + r) >> 1;


                bool b = false;
                for(auto x: tail[mid])
                {
                    if(envelopes[i][0] > x[0] && envelopes[i][1] > x[1])
                    {
                        l = mid + 1;
                        b = true;
                        break;
                    }
                }
                if(!b)
                    r = mid;
            }


            if(l < tail.size()) {
                tail[l].push_back(envelopes[i]);
            }


        }
        return tail.size();
    }
};
```

一维
```
static bool myfunc(vector<int> a, vector<int> b)
{
    if(a[0] == b[0])
        return a[1] > b[1];
    else
        return a[0] < b[0];
}
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), myfunc);
        vector<int> h;
        for(auto x: envelopes)
        {
            h.push_back(x[1]);
        }
        vector<int> tail;
        for(auto x: h)
        {
            if(!tail.size() || x > tail.back())
            {
                tail.push_back(x);
                continue;
            }
            int l = 0, r = tail.size() - 1;
            while(l < r)
            {
                int mid = (l + r + 1) >> 1;
                if(x <= tail[mid])
                    r = mid - 1;
                else
                    l = mid;
            }
            if(x > tail[l])
            {
                tail[l + 1] = min(tail[l + 1], x);
            }
            else
            {
                tail[l] = x;
            }
        }
        return tail.size();
    }
};
```
