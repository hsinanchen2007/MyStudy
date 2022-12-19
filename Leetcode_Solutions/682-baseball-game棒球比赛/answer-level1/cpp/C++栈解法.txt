```c++ []
class Solution {
public:
    int calPoints(vector<string>& ops) {
        if(ops.size() == 0) return 0;
        int ans = 0;
        stack<int> s;
        for (int i=0; i<ops.size(); ++i) {
        if (ops[i] == "+") {
            int top = s.top();
            s.pop();
            int newtop = top + s.top();
            s.push(top);
            s.push(newtop);
        }
        else if (ops[i] == "D")
            s.push(s.top() * 2);
        else if (ops[i] == "C"){
            s.pop();
        }
        else s.push(stoi(ops[i]));
        }
        while(!s.empty()){
            ans += s.top();
            s.pop();
        }
        return ans;
    }
};
```