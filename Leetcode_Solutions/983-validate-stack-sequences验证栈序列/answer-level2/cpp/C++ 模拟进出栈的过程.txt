```
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int n = pushed.size();
        for(int i = 0,j=0; i < n; i++){//模拟进栈
            s.push(pushed[i]);//先直接进栈
            //然后根据出栈序列决定是否出栈
            while(!s.empty()&&j<n&&s.top()==popped[j]) s.pop(),j++;//出栈
        }
        return s.empty() ? true:false;//若合法，则此时栈一定是空的
    }
```
