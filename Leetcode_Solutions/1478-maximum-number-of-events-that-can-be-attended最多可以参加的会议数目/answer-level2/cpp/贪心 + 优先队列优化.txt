T3:
这道题我没想到简单一点的算法。按天数采取一种贪心算法可以对。
考虑每一天， 因为一天只能参加一个会议。 所以如果那天有会议在召开， 则选择结束时间较早的会议。 这样可以使后面的天数中有更多选择， 答案不会变差。
因此， 维护当前正在召开的会议即可达到这个目的。 先把会议按照起始时间排序， 依次枚举每一天。 如果那一天恰好是某会议的开始时间则把它加入“当前正在召开的会议”。 然后从中选出一个离结束时间最近的来参加。
显然， 简单最标记会超时， 使用优先队列优化即可通过本题。

时间复杂度$O(nlogn)$.
空间复杂度$O(n)$

下面附上代码。 运行效率不高。要1636ms。

```
class Solution {
public:
    
    priority_queue<int, vector<int>, greater<int>> q;
    
    
    static bool mycmp(vector<int> x, vector<int> y){
        return x[0] < y[0];
    }

    
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        
        sort(events.begin(), events.end(), mycmp);
        
        int minDate, maxDate;
        
        minDate = events[0][0], maxDate = events[0][1];
        
        for(int i = 1; i < n; i++){
            minDate = min(minDate, events[i][0]);
            maxDate = max(maxDate, events[i][1]);
        }
        
        int curDate = minDate;
        
        int ans = 0, j = 0;
        while(curDate <= maxDate){
            while(!q.empty() && q.top() < curDate)q.pop();
            
            while(j < n && events[j][0] == curDate){q.push(events[j][1]);j++;}
            
            if(!q.empty()){ans++; q.pop();}
            curDate++;
        }
        
        return ans;
    }
};
```
