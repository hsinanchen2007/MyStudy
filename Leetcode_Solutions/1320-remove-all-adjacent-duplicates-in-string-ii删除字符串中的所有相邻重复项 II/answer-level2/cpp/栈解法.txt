```c++
class Solution {
public:
    string removeDuplicates(string s, int k) {
        deque<pair<char,int>>stk;
        int n = s.size();
        string res="";
        for(int i=0;i<n;i++){
            if(stk.empty()){
                stk.push_back(make_pair(s[i],1));
            }else {
                if(stk.back().first != s[i])stk.push_back(make_pair(s[i],1));
                else {
                    int a = stk.back().second;
                    stk.push_back(make_pair(s[i],a+1));
                    if(stk.back().second == k){
                        for(int j=0;j<k;j++)stk.pop_back();
                    }
                }
            }
        }
        while(!stk.empty()){
            res += stk.front().first;
            stk.pop_front();
        }
        return res;
    }
};
```