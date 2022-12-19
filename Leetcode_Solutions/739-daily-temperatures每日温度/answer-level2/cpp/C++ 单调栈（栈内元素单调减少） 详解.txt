```
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<pair<int,int> > s;//pair 存储每个温度以及其在数组T中的下标
        int n = T.size();
        vector<int> ans(n); 
        for(int i = 0; i < n; i++){//温度依次入栈，栈内元素保持单调减少(用于发现第一次升高温度)
            while(!s.empty()&&T[i] > s.top().first){//遇到高温
                //如果当前温度比栈顶高，那么就发现了相对于栈顶第一次升高温度的位置
                ans[s.top().second] = i-s.top().second;//位置差即为答案
                s.pop();
            }
            s.push({T[i],i});
        }
        return ans;//如果栈中还有数,默认都为零了
    }
```
