```
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int pos=0;
        for(int i=0;i<popped.size();++i){
            int value=popped[i];
            if(!s.empty()&&value==s.top()){
                s.pop();
            }
            else{
                while(pos<pushed.size()&&pushed[pos]!=value){
                    s.push(pushed[pos++]);
                }
                ++pos;
            }
            
        }
        return s.empty();
    }
};
```
