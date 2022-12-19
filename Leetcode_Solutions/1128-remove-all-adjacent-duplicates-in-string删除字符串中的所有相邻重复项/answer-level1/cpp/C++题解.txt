用C++写的，用了stack,string.append(),和reverse()几个函数

    string removeDuplicates(string S) {
        stack<char> s_stack;
        int slen=S.size();
        for(int i=0;i<slen;i++){
            if(s_stack.empty()){
                s_stack.push(S[i]);
            }
            else{
                if(s_stack.top()==S[i]){
                    s_stack.pop();
                }
                else
                    s_stack.push(S[i]);
            }
        }
        string res;
        while(!s_stack.empty()){
            res.append(1,s_stack.top());
            s_stack.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }