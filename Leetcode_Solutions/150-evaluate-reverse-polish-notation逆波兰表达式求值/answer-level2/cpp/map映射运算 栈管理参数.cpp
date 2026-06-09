```cpp
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string, function<long (long, long)>> m{ 
            {"+", [](long i,long j){return i+j;}}, 
            {"-", [](long i,long j){return i-j;}}, 
            {"*", [](long i,long j){return i*j;}},
            {"/", [](long i,long j){return i/j;}}
        };
        
        stack<long> ss;
        for(auto &s:tokens){
            if(m.count(s)==0){
                ss.push( atoi(s.c_str()) );
            }else{
                long a = ss.top(); ss.pop();
                long b = ss.top(); ss.pop();
                ss.push(m[s](b, a));
            }
        }
        return ss.top();
    }
};
```
