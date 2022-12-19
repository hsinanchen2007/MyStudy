```
class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        multimap<int, pair<pair<int,int>,int>> jobs;
        for(int i=0;i< endTime.size();i++)
        {
            jobs.insert(make_pair(endTime[i], make_pair(make_pair(startTime[i],profit[i]),-1)));
        }

        // bottom-up
        auto jobIt = jobs.begin();
        jobIt->second.second = jobIt->second.first.second;
        for(jobIt = next(jobIt);jobIt!=jobs.end();jobIt=next(jobIt))
        {
            auto validjobIt = jobs.upper_bound(jobIt->second.first.first);
            int p1 = jobIt->second.first.second;
            if (validjobIt!=jobs.begin())
            {
                p1 += prev(validjobIt)->second.second;
            }
            jobIt->second.second = max(p1, prev(jobIt)->second.second);
        }
        return prev(jobIt)->second.second;

        // top-down
        // return jobDP(jobs, jobs.end());
    }
    int jobDP(multimap<int, pair<pair<int,int>,int>>& jobs, 
        multimap<int, pair<pair<int,int>,int>>::iterator cur)
    {
        if (cur==jobs.begin()) return 0;
        cur = prev(cur);
        if (cur==jobs.begin())
        {
            return cur->second.first.second;
        }
        if (cur->second.second>=0) return cur->second.second;
        auto validjobIt = jobs.upper_bound(cur->second.first.first);
        int p1 = cur->second.first.second + jobDP(jobs, validjobIt);
        int p2 = jobDP(jobs, cur);
        int p = max(p1, p2);
        cur->second.second = p;
        return p;
    }
};
```
