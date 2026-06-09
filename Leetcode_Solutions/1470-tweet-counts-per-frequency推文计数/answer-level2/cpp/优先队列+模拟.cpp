STL在模拟里面真的非常好用。
```
class TweetCounts {
public:
    TweetCounts() {
        
    }
    priority_queue<int,vector<int>, greater<int> > q[10005],p; 
    map<string,int>mp;
    int ans=1;
    void recordTweet(string tweetName, int time) {
        if(mp[tweetName]==0)
        {
            mp[tweetName]=ans;
            ans++;
        }
        q[mp[tweetName]].push(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        int jg=60;
        if(freq=="hour") jg*=60;
        if(freq=="day") jg*=60*24;
        vector<int>v;
        p=q[mp[tweetName]];
        int m=ceil((endTime-startTime+1)*1.0/jg),s,e,cnt=0;
        for(int i=0;i<m;i++)
        {
            s=startTime+jg*i;
            e=min(s+jg-1,endTime);
            while(!p.empty()&&p.top()<s) p.pop();
            while(!p.empty()&&p.top()>=s&&p.top()<=e)
            {
                cnt++;
                p.pop();
            }
            v.push_back(cnt);
            cnt=0;
        }
        return v;
    }
};
```
