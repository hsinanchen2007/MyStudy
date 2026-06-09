离散化时间，用树状数组统计[1,time]时间内的最大收益。
对于一个[start,end]，更新树状数组的end，更新方法：update(end, max(1,start)+profit)

代码中的dp是多余的。

```cpp
class Solution {
public:
    
    // 当前时刻i的最大profit  dp[i] = max{dp[j]+v};
    vector<int> v;
    int cnt;
    int star[50005],endt[50005];
    int dp[1000000];
      struct node {
        int be, ed;
          
        int pro;
        
    } t[50005];
    static bool cmp(node i, node j) {
        return j.ed == i.ed ? i.be < j.be : i.ed < j.ed;
    }
    int h[1000000];
    int N;
    int lowbit(int x)
     {
         return x&(-x);
     }
      void update(int x, int v)
    {
        while(x<=N)
        {
            h[x]=v;
            for(int i=1;i<lowbit(x);i<<=1)
            h[x]=max(h[x],h[x-i]);
            x+=lowbit(x);
        }
        return ;
    }
    int findans(int begin,int end)
    {
        int ans=0;
        while(end>=begin)
        {
            ans=max(ans,h[end]);
            end--;
            for(;end-lowbit(end)>=begin;end-=lowbit(end))
            ans=max(ans,h[end]);
        }


        return ans;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        for(int i = 0; i < n; ++i)
            t[i].be = startTime[i], t[i].ed = endTime[i], t[i].pro = profit[i];
        sort(t, t+n, cmp);
        for(auto&it : endTime) 
            v.push_back(it);
        for(auto&it : startTime)
            v.push_back(it);
        sort(v.begin(), v.end());
        v.erase( unique(v.begin(),v.end()), v.end());
        // a.erase(unique(a.begin(),a.end()),a.end())
        for(int i = 0; i < n; ++i) {
            endt[i] = int(lower_bound(v.begin() , v.end() , t[i].ed) - v.begin())+1;
            star[i] = int(lower_bound(v.begin() , v.end() , t[i].be) - v.begin())+1;
         
        }
     
	    N = v.size();
        int mx = 0;
        for(int i = 0; i < n; ++i) {
            dp[endt[i]] = max(mx, findans(1, star[i])+t[i].pro);
            update(endt[i], dp[endt[i]]);
        
            // cout << t[i].ed << " dp:" << dp[endt[i]] <<" " << t[i].be << " dp:" << dp[star[i]] <<" " << t[i].pro << endl;
            mx = max(mx, dp[endt[i]]);
        }
        return mx;    
    }
    /*
    1 2 3 4 6 . 3 5 10 6 9
    0 1 2 3 5   3 4 7  5 6
   */
}

```