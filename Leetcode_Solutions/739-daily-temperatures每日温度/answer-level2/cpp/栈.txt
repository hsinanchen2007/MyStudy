class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        if(!T.size()) return {};
        vector<int> day(T.size(),0);
        stack<int> s;
        for(int i=0;i<T.size();i++){
            while(!s.empty() && T[i]>T[s.top()] ){
                day[s.top()]=i-s.top();
                s.pop();
            }
            s.push(i);
        }
        return day;
    }
};